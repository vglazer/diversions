#include <iostream>
#include <stdlib.h>

#include "MemPool.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <num_chunks>" << std::endl;
        return -1;
    }

    MemPool<int, 3> pool;
    std::cout << "block size: " << pool.getBlockSize() << std::endl;

    int num_chunks = atoi(argv[1]);
    for (int i = 0; i < num_chunks; ++i)
    {
        int * chunk = pool.getMem();
        std::cout << "got chunk with address " << chunk << " and value " 
                  << *chunk << std::endl;
    }

    return 0;
}
