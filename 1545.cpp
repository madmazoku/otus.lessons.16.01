#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

static const int char_start = 'a';
static const int char_range = 'z'-'a';

void skip_until_new_line() {
    while(!std::cin.eof())
        if(std::cin.get() == '\n')
            return;
}

int main() {
    size_t dict_size;
    std::cin >> dict_size;
    skip_until_new_line();
    
    int dict[char_range * (char_range + 1)];
    std::memset(dict, 0, sizeof(int) * char_range * (char_range + 1));

    for(size_t n = 0; n < dict_size; ++n) {
        int c1 = std::cin.get();
        int c2 = std::cin.get();
        skip_until_new_line();

        int pos = (c1 - char_start) * (char_range + 1);

        dict[pos + ++dict[pos]] = c2;
    }

    int cf = std::cin.get();

    int pos = (cf - char_start) * (char_range + 1);
    for(size_t i = 0; i < dict[pos]; ++i)
        std::cout << (char)(cf) << (char)(dict[pos + i + 1]) << std::endl;

    return 0;
}

// #include <iostream>
// #include <string>
// #include <map>
// #include <set>

// using dict_t = std::map<char, std::set<char>>;

// int main() {
//     size_t dict_size;
//     std::cin >> dict_size;

//     dict_t dict;

//     std::string line;
//     std::getline(std::cin, line);
//     for(size_t n = 0; n < dict_size; ++n) {
//         std::getline(std::cin, line);
//         dict[line[0]].insert(line[1]);
//     }
//     std::getline(std::cin, line);

//     auto s = dict.find(line[0]);
//     if(s != dict.end())
//         for(auto c : s->second)
//             std::cout << line[0] << c << std::endl;

//     return 0;
// }