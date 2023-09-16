#include "Game.h"



int main(int argc, char *argv[]) {
    Game game;
    // board is divided in coloms
    struct position moves[] = {{1,6},{1,5},{0,1},{0,2},{0,6},{0,5}};
    game.move_piece(moves[0], moves[1]);
    game.move_piece(moves[2], moves[3]);
    game.move_piece(moves[4], moves[5]);
    // game.move_piece(moves[4], moves[5]);
    // game.move_piece(moves[6], moves[7]);
    // game.move_piece(moves[6], moves[7]);
    game.game_status();
    return 0;
}
