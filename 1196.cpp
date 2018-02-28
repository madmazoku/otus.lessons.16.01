#include <iostream>
#include <string>
#include <set>

using dict_t = std::set<size_t>;

int main() {
    size_t history_size;
    std::cin >> history_size;

    dict_t dict;

    size_t date;
    for(size_t n = 0; n < history_size; ++n) {
        std::cin >> date;
        dict.insert(date);
    }

    size_t answer_size;
    std::cin >> answer_size;

    size_t matched = 0;
    for(size_t n = 0; n < answer_size; ++n) {
        std::cin >> date;
        if(dict.find(date) != dict.end())
            ++matched;
    }

    std::cout << matched << std::endl;

    return 0;
}