#include "include/chess_game/Game.h"
#include "include/chess_game/Chess_pieces.h"
#include <array>

using namespace chess;

//private implementation function
static framework::Board<8,8,6,2,32> initilization(){
    const std::array<const Player,2> player_list;
    const std::array<const framework::Piece,6> piece_list =
    {
        Pawn(),
        Knight(),
        Bishop(),
        Rook(),
        Queen(),
        King()
    };
    const std::array<const framework::cell_configuration,32> board_conf = 
    {
        //black pawn
        0,1,0,1,
        1,1,0,1,
        2,1,0,1,
        3,1,0,1,
        4,1,0,1,
        5,1,0,1,
        6,1,0,1,
        7,1,0,1,
        //white pawn
        0,6,0,0,
        1,6,0,0,
        2,6,0,0,
        3,6,0,0,
        4,6,0,0,
        5,6,0,0,
        6,6,0,0,
        7,6,0,0,
        //black Knight
        1,0,1,1,
        6,0,1,1,
        //white Knight
        1,7,1,1,
        6,7,1,1,
        //black Bishop
        2,0,2,1,
        5,0,2,1,
        //white Bishop
        2,7,2,1,
        5,7,2,1,
        //black Rook
        0,0,3,1,
        7,0,3,1,
        //white Rook
        0,7,3,1,
        7,7,3,1,
        //black Queen
        3,0,4,1,
        //white Queen
        3,7,4,1,
        //black King
        4,0,5,1,
        //white King
        4,7,5,1
    };
    return framework::Board<8,8,6,2,32>(piece_list,player_list,board_conf);
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
