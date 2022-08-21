#include <cstdlib>
#include <cstring>
#include "golf.h"
#include <iomanip>
#include <iostream>
#include <string>

void _set_player(golf& player, const char* name, int _handicap) {
    strcpy(player._full_name, name);
    player.handicap = _handicap;
}

int _set_player(golf& player) {
    int _return = 0;
    std::string _player_name;
    std::cout << "Enter player name: " << std::endl;
    std::cin.ignore();
    getline(std::cin, _player_name);
    strcpy(player._full_name, _player_name.c_str());
    if(_player_name[0] != '\0')
        _return = 1;
    std::cout << "Enter player handicap: ";
    std::cin >> player.handicap;
    return _return;
}

void _set_handicap(golf& player, int _handicap) {
    player.handicap = _handicap;
}

void _show_player_data(const golf& player) {
    std::cout << "\n\tPlayer data:" << std::endl;
    std::cout << " - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << ":         Name         : " << "Handicap :" << std::endl;
    std::cout << " - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << ':' << "  " << std::setw(20) << std::left << player._full_name << ':';
    std::cout << std::setw(10) << std::right << player.handicap << ':' << std::endl;
    std::cout << " - - - - - - - - - - - - - - - - -" << std::endl;
}
