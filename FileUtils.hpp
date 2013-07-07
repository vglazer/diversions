#ifndef __FILE_UTILS_HPP__
#define __FILE_UTILS_HPP__

#include <string>
#include <vector>

namespace FileUtils
{
    // returns lines in a new vector, throws an exception on failure
    std::vector<std::string> read_lines(const std::string & file_name);
}

#endif // __FILE_UTILS_HPP__