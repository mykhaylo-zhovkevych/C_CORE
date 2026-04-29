#ifndef PLAYER_H
#define PLAYER_H

typedef enum {
    BEAR, 
    ACTIVIST,
    CLAIRVOYANT,
    HEALVER,
    TOWNSPERSON,
    ROLE_COUNT
} Role;

typedef struct Player_protected Player_protected;

typedef struct Player {
    int player_id;
    Role role;

    // Protected
    Player_protected* protected_data;
} Player;

/*
* Public Methods
*/
void Player_reset(Player* self);
int Player_is_alive(const Player* self);
void Player_eliminate(Player* self);
int Player_can_vote(const Player* self);
void Player_ban_vote(Player* self);
int Player_is_bitten(const Player* self);

// Does not act on a Player instance (static method)
const char* Player_role_to_string(Role role);

#endif