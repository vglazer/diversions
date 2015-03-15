#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <string.h>
#include <fstream>

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: <pattern> <text file>" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[2]);
    if (!ifs)
    {
        std::cerr << "could not open " << argv[2] << " for input!" << std::endl;
        return -1;
    }

    std::string line;
    std::vector<char> text;
    while (std::getline(ifs, line))
    {
        std::copy(line.begin(), line.end(), std::back_inserter(text));
        if (ifs.peek() != EOF)
        {
            text.push_back('\n');
        }
    }

    std::vector<char>::const_iterator cit = std::search(text.begin(), text.end(), 
                                                        argv[1], argv[1]+strlen(argv[1]));
    if (cit == text.cend())
    {
        std::cout << "Pattern not found in corpus!" << std::endl;
    }
    else
    {
        std::cout << "Pattern found at index " << std::distance(text.cbegin(), cit) 
                  << std::endl;
    }

    return 0;
}