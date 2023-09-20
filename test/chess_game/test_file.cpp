#include "include/framework/Board.h"
#include "include/chess_game/Chess_pieces.h"
#include "include/chess_game/Game.h"

using namespace framework;

int main(int argc, char *argv[]) {

    chess::Chess_game game;
    position moves[] = 
    {
        0,6,
        0,5,
        0,1,
        0,2,
    };
    for(int i=0;i<sizeof(moves) / sizeof(moves[0]);i+=2)
    {
        game.move_piece(moves[i], moves[i+1]);
    }
    game.game_status();   
    return 0;
}
