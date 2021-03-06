#include <fstream>
#include <iostream>
#include <stdexcept> // for std::runtime_error

#include "FileUtils.hpp"

// Functions for working with files
namespace FileUtils
{
    // returns lines in a new vector, throws exception on failure
    std::vector<std::string> read_lines(const std::string & file_name)
    {
        std::ifstream ifs(file_name.c_str()); // dtor will close handle
        if (!ifs)
        {
            throw std::runtime_error("Could not open " + file_name + " for input!");
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(ifs, line))
        {
            lines.push_back(line);
        }

        return lines;
    }

    // populates existing vector with lines in a new vector, returns false on failure
    bool read_lines(const std::string & file_name, std::vector<std::string> & lines)
    {
        lines.clear(); // in case caller forgot to clean up

        std::ifstream ifs(file_name.c_str()); // dtor will close handle
        if (!ifs)
        {
            // silent failure
            return false;
        }

        std::string line;
        while (std::getline(ifs, line))
        {
            lines.push_back(line);
        }

        return true;
    }
} // namespace FileUtils
