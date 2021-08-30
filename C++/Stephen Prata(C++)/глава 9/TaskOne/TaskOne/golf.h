#ifndef GOLF_H
#define GOLF_H

const int length = 40;

struct golf {
    char _full_name[length];
    int handicap;
};

void _set_player(golf& player, const char* name, int _handicap);

int _set_player(golf& player);

void _set_handicap(golf& player, int _handicap);

void _show_player_data(const golf& player);

#endif // GOLF_H
