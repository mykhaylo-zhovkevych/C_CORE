#include "game/game.h"
#include "util/util.h"
#include "../player/player.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Game {
    int num_players;
    int num_bears_left;
    int num_townspeople_left;
    int is_night;

    int players_bitten_ids[NUM_BEARS];
    int bites_this_round;
    int player_healed_id;
    Player** players;
}



int main() {

}