#include <stdlib.h> // for EXIT_{SUCCESS, FAILURE}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::copy
#include <iterator> // for std::ostream_iterator

#include "FileUtils.hpp"

#define __USE_EXCEPTIONS__

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <file_name>" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> lines;
#ifdef __USE_EXCEPTIONS__
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
#endif // __USE_EXCEPTIONS__

    std::copy(lines.begin(), lines.end(),
              std::ostream_iterator<std::string>(std::cout, "\n"));

    return EXIT_SUCCESS;
}