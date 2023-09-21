#include "include/framework/Board.h"
#include "include/chess_game/generic_chess_piece.h"
#include "include/chess_game/Game.h"

using namespace framework;

int main(int argc, char *argv[]) {

    chess::Chess_game game;
    position moves[] = 
    {
        4,6,
        4,5,
        4,1,
        4,3,
        3,7,
        6,4,
        3,0,
        5,2,
        6,4,
        0,4,
        5,2,
        5,5,
        7,6,
        7,4,
        3,1,
        3,2,
        7,7,
        7,5,
        2,0,
        5,3,
        3,6,
        3,4,
        4,3,
        3,4,
        1,7,
        2,5,
        1,6,
        1,5,
    };
    for(int i=0;i<sizeof(moves) / sizeof(moves[0]);i+=2)
    {
        game.move_piece(moves[i], moves[i+1]);
    }
    game.game_status();   
    return 0;
}
