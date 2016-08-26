#include <vector>
#include <list>

#include <stddef.h> // for size_t

//
// A memory pool for objects of type T; _blockSize is the
// number of memory chunks per block
//
template <typename T, size_t _blockSize = 1024>
class MemPool
{
	public:
		typedef std::vector<T*> Blocks;
		typedef std::list<T*> FreeList;

		// Destructor: free all allocated memory blocks
		~MemPool()
		{
			for (typename Blocks::const_iterator cit = _blocks.begin(); cit != _blocks.end(); ++cit)
				delete(*cit);
		}

		// Get a chunk of memory from the pool
		T* getMem() 
		{
			// Allocate a new block if we've run out of chunks
			if (_freeList.empty())
				allocateBlock();

			// Grab the next chunk off the free list 
			T* chunk = _freeList.front();		
			_freeList.pop_front();

			return chunk;
		}

		// Return the specified chunk of memory to the pool 
		void putMem(T* chunk)
		{
			_freeList.push_front(chunk);
		}

		// The number of memory chunks per block
		int getBlockSize() const
		{
			return _blockSize;
		}

	private:
		// Allocate a new block of memory chunks on the heap 
		void allocateBlock()
		{
			// Allocate a block of raw memory
			T* block = static_cast<T*>(operator new(_blockSize*sizeof(T))); 

			// Add pointers to all chunks to the free list
			for (unsigned int i = 0; i < _blockSize; ++i)
				_freeList.push_back(&block[i]);
		
			// Keep track of the block's address, so we can delete it later
			_blocks.push_back(block);
		}

		// Pointers to the available memory chunks
		FreeList _freeList;

		// Pointers to the allocated memory blocks (for later deletion)
		Blocks _blocks;
}; // MemPool
