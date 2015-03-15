#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: <pattern> <numbers file>" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[2]);
    if (!ifs)
    {
        std::cerr << "could not open " << argv[2] << " for input!" << std::endl;
        return -1;
    }

    std::istringstream ss(argv[1]);
    std::vector<double> pattern;
    std::string str;
    while (ss >> str)
    {
        pattern.push_back(atof(str.c_str()));
    }

    std::vector<double> corpus;
    while (ifs >> str)
    {
        corpus.push_back(atof(str.c_str()));
    }

    std::vector<double>::const_iterator cit = std::search(corpus.begin(), corpus.end(), 
                                                          pattern.begin(), pattern.end());
    if (cit == corpus.cend())
    {
        std::cout << "Pattern not found in corpus!" << std::endl;
    }
    else
    {
        std::cout << "Pattern found at index " << std::distance(corpus.cbegin(), cit) 
                  << std::endl;
    }

    return 0;
}

