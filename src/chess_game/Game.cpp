#include "Game.h"
#include <array>
#include "Chess_pieces.h"

using namespace chess;

//private implementation function
void starting_board_configuration()
{
}

static framework::Board<8,8,6,2> initilization(){
    const std::array<Player,2> player_list;
    const std::array<framework::Piece,6> piece_list =
    {
        chess::Pawn(),
        chess::Knight(),
        chess::Bishop(),
        chess::Rook(),
        chess::Queen(),
        chess::King()
    };
    return framework::Board<8,8,6,2>(piece_list,player_list,starting_board_configuration);
}



//public
chess::Chess_game::Chess_game() : board(initilization())
{
    //ok to be empty
}

void Chess_game::game_status() const
{
    this->board.print_board();
}
