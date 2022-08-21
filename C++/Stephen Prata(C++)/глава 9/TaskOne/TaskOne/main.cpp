#include <cstring>
#include "golf.h"
#include <iostream>



int main() {
    golf* players;
    int _players_count = 0;
    int _number_of_players = 0;
    std::cout << "enter the number of players: ";
    std::cin >> _players_count;
    players = new golf[_players_count];
    for(int i = 0; i < _players_count; ++i) {
        if(_set_player(players[i]) == 0)
            break;
        ++_number_of_players;
    }
    for(int i = _number_of_players; i < _players_count; ++i) {
        _set_player(players[i], "Undefined", 0);
    }
    for(int i = 0; i < _players_count; ++i)
        _show_player_data(players[i]);
    _set_handicap(players[0], 5);
    _show_player_data(players[0]);
    return 0;
}
/*
    golf ann;
    _set_player(ann, "Ann Birdfree", 24);
    golf andy;
    _set_player(andy);
    _show_player_data(ann);
    _show_player_data(andy);
*/

/*
        strcpy(players[i]._full_name, "Undefined");
        players[i].handicap = 0;
*/
