#include <iostream>
#include <string>
#include <map>
#include <set>

static const size_t team_size = 3;

using team_t = std::set<std::string>;
using dict_t = std::map<std::string, team_t>;
using inum_t = std::map<std::string, size_t>;

int main() {
    size_t teams_count;
    std::cin >> teams_count;

    dict_t dict;
    std::string teammate[team_size];
    for(size_t n = 0; n < teams_count; ++n) {
        for(size_t i = 0; i < team_size; ++i)
            std::cin >> teammate[i];
        for(size_t i = 0; i < team_size; ++i) {
            team_t &team = dict[teammate[i]];
            for(size_t j = 0; j < team_size; ++j)
                if(teammate[i] != teammate[j])
                    team.insert(teammate[j]);
        }
    }

    inum_t inum;

    team_t current_teammates;
    current_teammates.insert("Isenbaev");
    size_t current_inum = 0;
    while(!current_teammates.empty()) {
        team_t teammates;
        for(auto ct : current_teammates)
            inum[ct] = current_inum;
        for(auto ct : current_teammates)
            for(auto t : dict[ct])
                if(inum.find(t) == inum.end())
                    teammates.insert(t);
        ++current_inum;
        current_teammates = teammates;
    }

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