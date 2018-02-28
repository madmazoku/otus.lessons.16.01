#include <iostream>
#include <string>
#include <map>
#include <set>

using dict_t = std::map<std::string, size_t>;

int main() {
    size_t name_count;
    std::cin >> name_count;

    dict_t dict;

    std::string line;
    std::getline(std::cin, line);
    for(size_t n = 0; n < name_count; ++n) {
        std::getline(std::cin, line);
        ++dict[line];
    }
    for(auto n : dict)
        if(n.second > 1)
            std::cout << n.first << std::endl;

    return 0;
}