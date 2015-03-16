#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " <string>" << std::endl;
        return -1;
    }

    std::string s(argv[1]);
    for (int low = 0, high = s.length() - 1; high > low; ++low, --high)
    {
        std::swap(s[low], s[high]);
    }

    std::cout << "reversed string: " << s << std::endl;

    return 0;
}