#include <iostream>
#include <string>
#include <map>
#include <set>

static const size_t team_size = 3;

using team_t = std::set<std::string>;
using dict_t = std::map<std::string, team_t>;
using inum_t = std::map<std::string, size_t>;

void set_inum(const dict_t &dict, inum_t &inum, const std::string &teammate, size_t in) {
    auto itm = inum.find(teammate);
    if(itm != inum.end() && itm->second <= in)
        return;

    inum[teammate] = in;

    auto dtm = dict.find(teammate);
    if(dtm != dict.end())
        for(auto d : dtm->second)
            set_inum(dict, inum, d, in + 1);
}

int main() {
    size_t teams_count;
    std::cin >> teams_count;

    dict_t dict;
    std::string teammate[team_size];
    for(size_t n = 0; n < teams_count; ++n) {
        for(size_t i = 0; i < team_size; ++i)
            std::cin >> teammate[i];
        for(size_t i = 0; i < team_size; ++i)
            for(size_t j = 0; j < team_size; ++j)
                if(i != j)
                    dict[teammate[i]].insert(teammate[j]);
    }

    inum_t inum;
    set_inum(dict, inum, "Isenbaev", 0);

    for(auto tm : dict) {
        std::cout << tm.first << ' ';
        auto n = inum.find(tm.first);
        if(n != inum.end())
            std::cout << n->second;
        else
            std::cout << "undefined";
         std::cout << std::endl;
     }

    return 0;
}