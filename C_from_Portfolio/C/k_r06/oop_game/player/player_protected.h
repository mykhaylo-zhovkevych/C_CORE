#ifndef PLAYER_PROTECTED_H
#define PLAYER_PROTECTED_H

#include "player.h"

struct Player_protected {
    int is_alive;
    int is_bitten;
    int can_vote;
};

void super(Player *self, const int player_id, const Role role);

#endif
