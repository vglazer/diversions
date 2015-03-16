#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: " << argv[0] << " <input (text)> <output (binary)>" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[1]);
    if (!ifs)
    {
        std::cerr << "Cannot open " << argv[1] << " for input!" << std::endl;
        return -1;
    }

    std::ofstream ofs(argv[2], std::ios::out|std::ios::binary);
    if (!ofs)
    {
        std::cerr << "Cannot open " << argv[2] << " for output!" << std::endl;
        return -1;
    }

    std::string str;
    while (ifs >> str)
    {
        double num = atof(str.c_str());
        ofs.write(reinterpret_cast<char *>(&num), sizeof(num));
    }

    return 0;
}