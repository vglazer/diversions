#ifndef __FILE_UTILS_HPP__
#define __FILE_UTILS_HPP__

#include <string>
#include <vector>

// Functions for working with files
namespace FileUtils
{
    // returns lines in a new vector, throws an exception on failure
    std::vector<std::string> read_lines(const std::string & file_name);

    // populates existing vector with lines in a new vector, returns false on failure
    bool read_lines(const std::string & file_name,
                    std::vector<std::string> & lines);
} // namespace FileUtils

#endif // __FILE_UTILS_HPP__
