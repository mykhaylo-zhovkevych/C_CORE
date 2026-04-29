# include "game.h"
#include "../player/player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Private
 */
struct Game {
    int num_players;
    int num_bears_left;
    int num_townspeople_left;
    int is_night;

    int players_bitten_ids[NUM_BEARS];
    int bites_this_round;
    int player_healed_id;
    Player** players;
};

void Game_init_round_properties(Game* self) {
    for (int i = 0; i < NUM_BEARS; i++) {
        self->players_bitten_ids[i] = -1;
    }
    self->bites_this_round = 0;
    self->player_healed_id = -1;
}

static Player** Game_init_game_players(const int num_players) {
    Player** players = malloc(num_players * sizeof(Player*));
    if (!players) exit(EXIT_FAILURE);

    return players;
}

/* 
 * Private
 */
Game* Game_ctor(const int num_players) {

    Game* game = malloc(sizeof(Game));
    if (!game) exit(EXIT_FAILURE);

    game->num_players = num_players;
    game->is_night = 1;
    game->num_bears_left = NUM_BEARS;
    game->num_townspeople_left = num_players - NUM_BEARS;
    Game_init_round_properties(game);

	game->players = Game_init_game_players(num_players);
    
    return game;
}
void Game_loop(Game* self) {
    // TODO
}
void Game_dtor(Game* self) {
    free(self);
}