#ifndef __TEXT_UTILS_HPP__
#define __TEXT_UTILS_HPP__

#include <string>
#include <vector>

// Functions for working with text
namespace TextUtils
{
    // join a bunch of tokens together using the specified delimiter to form a chunk of text
    std::string join(const std::vector<std::string> & lines, const std::string & delim = ",");

    // convert a chunk of text into a bunch of tokens by splitting on the given delimiter
    unsigned int split(const std::string & text, std::vector<std::string> & tokens,
                       const std::string & delim = ",");
} // namespace TextUtils

#endif // __TEXT_UTILS_HPP__
