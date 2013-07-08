#include <sstream>

#include "TextUtils.hpp"

// Functions for working with files
namespace TextUtils
{
    // join a bunch of tokens together using the specified delimiter to form a chunk of text
    std::string join(const std::vector<std::string> & tokens, const std::string & delim)
    {
        std::ostringstream oss;
        for (std::vector<std::string>::const_iterator cit = tokens.begin(); cit != tokens.end(); ++cit)
        {
            oss << *cit;

            if (cit + 1 != tokens.end())
            {
                oss << delim;
            }
        }

        return oss.str();
    }

    // convert a chunk of text into a bunch of tokens by splitting on the given delimiter
    unsigned int split(const std::string & text, std::vector<std::string> & tokens,
                       const std::string & delim)
    {
        tokens.clear(); // in case caller forgets

        size_t first = 0, last;
        for (;;)
        {
            last = text.find(delim, first);
            if (last == std::string::npos)
            {
                tokens.push_back(text.substr(first));
                break;
            }
            else
            {
                tokens.push_back(text.substr(first, last - first));
                first = last + 1;
            }
        }

        return tokens.size();
    }
} // namespace TextUtils
