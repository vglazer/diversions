#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: " << argv[0] << " <input (binary)> <output (text)>" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[1], std::ios::in|std::ios::binary);
    if (!ifs)
    {
        std::cerr << "Cannot open " << argv[1] << " for input!" << std::endl;
        return -1;
    }

    std::ofstream ofs(argv[2]);
    if (!ofs)
    {
        std::cerr << "Cannot open " << argv[2] << " for output!" << std::endl;
        return -1;
    }

    double num;
    for (; ifs; ifs.read(reinterpret_cast<char*>(&num), sizeof(num)))
    {
        ofs << num << " ";
    }
    ofs << std::endl;

    return 0;
}
