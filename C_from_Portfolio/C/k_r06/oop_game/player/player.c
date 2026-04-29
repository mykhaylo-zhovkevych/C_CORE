#include "player.h"
#include "player_protected.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Player_protected* Player_protected_ctor() {
    Player_protected* protected = malloc(sizeof(Player_protected));
    if (!protected) exit(EXIT_FAILURE);
    
    protected->is_alive = 1;
    protected->can_vote = 1;
    protected->is_bitten = 0;

    return protected;
}


// Protected
void super(Player *self, const int player_id, const Role role) {
    self->player_id = player_id;
    self->role = role;
    self->protected_data = Player_protected_ctor();
}

//Public
void Player_reset(Player* self) {
    self->protected_data->can_vote = 1;
    self->protected_data->is_bitten = 0;
}

int Player_is_alive(const Player* self) {
    return self->protected_data->is_alive;
}

void Player_eliminate(Player* self) {
    self->protected_data->is_alive = 0;
}

int Player_can_vote(const Player* self) {
    return self->protected_data->can_vote;
}

void Player_ban_vote(Player* self) {
    if (!self->protected_data->is_alive) {
        printf("Player %d is already eliminated and cannot be banned from voting.\n", self->player_id);
        return;
    }
    self->protected_data->can_vote = 0;
}

int Player_gets_bitten(Player* self) {
    if (!self->protected_data->is_alive) {
        printf("Player %d is already eliminated and cannot be bitten.\n", self->player_id);
        return 0;
    }
    else if (self->role == BEAR) {
        printf("Player %d is a bear and cannot be bitten.\n", self->player_id);
        return 0;
    }
    self->protected_data->is_bitten = 1;
    return 1;
}
