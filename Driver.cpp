#define __USE_EXCEPTIONS__ 0

#include <stdlib.h> // for EXIT_{SUCCESS, FAILURE}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::copy
#include <iterator> // for std::ostream_iterator

#include "FileUtils.hpp"
#include "TextUtils.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <file_name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> lines;
#if __USE_EXCEPTIONS__
    try
    {
        lines = FileUtils::read_lines(argv[1]);
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
#else
    if (!FileUtils::read_lines(argv[1], lines))
    {
        std::cerr << "Failed to read lines from " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }
#endif // __USE_EXCEPTIONS__

    std::vector<std::string> tokens;
    for (std::vector<std::string>::const_iterator cit = lines.begin(); cit != lines.end(); ++cit)
    {
        std::cout << "line: '" << *cit << "'" << std::endl;
        TextUtils::split(*cit, tokens, " ");

        std::cout << "tokens: ";
        std::copy(tokens.begin(), tokens.end(),
                  std::ostream_iterator<std::string>(std::cout, " >> "));
        std::cout << std::endl;

        std::string line = TextUtils::join(tokens, " ");
        std::cout << "reconstituted line: '" << line << "'" 
                  << std::endl << std::endl;
    }

    return EXIT_SUCCESS;
}
