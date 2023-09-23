#include "include/framework/Board.h"
#include "include/chess_game/generic_chess_piece.h"
#include "include/chess_game/Game.h"

using namespace framework;

int main(int argc, char *argv[]) {

    chess::Chess_game game;
    position moves[] = 
    {
        1,7,
        2,5,
        1,0,
        2,2,
        6,7,
        5,5,
        6,0,
        5,2,
        2,5,
        2,3,
    };
    for(int i=0;i<sizeof(moves) / sizeof(moves[0]);i+=2)
    {
        game.move_piece(moves[i], moves[i+1]);
    }
    game.game_status();   
    return 0;
}
