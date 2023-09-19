#include "include/chess_game/Game.h"
#include "include/chess_game/Chess_pieces.h"
#include <array>

using namespace chess;

//private implementation function
static framework::Board<8,8,6,2,2> initilization(){
    const std::array<const Player,2> player_list;
    const std::array<const framework::Piece,6> piece_list =
    {
        Pawn(),
        Knight(),
        Pawn(),
        Pawn(),
        Pawn(),
        Pawn()
        // King()
        // Rook(),
        // Queen(),
        // King()
    };
    const std::array<const framework::cell_configuration,2> board_conf = 
    {
        0,1,0,1,
        1,1,0,1
    };
    return framework::Board<8,8,6,2,2>(piece_list,player_list,board_conf);
}

//public
Chess_game::Chess_game() : board(initilization())
{
    //ok to be empty
}

Chess_game::~Chess_game()
{
    //ok to be empty
}

void Chess_game::game_status() const
{
    this->board.print_board();
}
