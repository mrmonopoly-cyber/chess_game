#include "include/chess_game/Game.h"
#include "include/chess_game/Chess_pieces.h"
#include <array>

using namespace chess;

//private implementation function
static framework::Board<8,8,6,2,32> initilization(){
    const std::array<const framework::Piece*,6> piece_list =
    {
        new Pawn(),
        new Knight(),
        new Bishop(),
        new Rook(),
        new Queen(),
        new King()
    };
    const std::array<const framework::cell_configuration,32> board_conf = 
    {
        //black pawn
        0,1,piece_list[0]->piece_name(),1,
        1,1,piece_list[0]->piece_name(),1,
        2,1,piece_list[0]->piece_name(),1,
        3,1,piece_list[0]->piece_name(),1,
        4,1,piece_list[0]->piece_name(),1,
        5,1,piece_list[0]->piece_name(),1,
        6,1,piece_list[0]->piece_name(),1,
        7,1,piece_list[0]->piece_name(),1,
        //whpiece_list[0]->piece_name()te pawn
        0,6,piece_list[0]->piece_name(),0,
        1,6,piece_list[0]->piece_name(),0,
        2,6,piece_list[0]->piece_name(),0,
        3,6,piece_list[0]->piece_name(),0,
        4,6,piece_list[0]->piece_name(),0,
        5,6,piece_list[0]->piece_name(),0,
        6,6,piece_list[0]->piece_name(),0,
        7,6,piece_list[0]->piece_name(),0,
        //black Knight
        1,0,piece_list[1]->piece_name(),1,
        6,0,piece_list[1]->piece_name(),1,
        //white Knight
        1,7,piece_list[1]->piece_name(),0,
        6,7,piece_list[1]->piece_name(),0,
        //black Bishop
        2,0,piece_list[2]->piece_name(),1,
        5,0,piece_list[2]->piece_name(),1,
        //white bishop
        2,7,piece_list[2]->piece_name(),0,
        5,7,piece_list[2]->piece_name(),0,
        //black Rook
        0,0,piece_list[3]->piece_name(),1,
        7,0,piece_list[3]->piece_name(),1,
        //white Rook
        0,7,piece_list[3]->piece_name(),0,
        7,7,piece_list[3]->piece_name(),0,
        //black Queen
        3,0,piece_list[4]->piece_name(),1,
        //white Queen
        3,7,piece_list[4]->piece_name(),0,
        //black King
        4,0,piece_list[5]->piece_name(),1,
        //whire King
        4,7,piece_list[5]->piece_name(),0
    };
    return framework::Board<8,8,6,2,32>(piece_list,board_conf);
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

void Chess_game::restart_game()
{
    board.reset_board();
}
void Chess_game::move_piece(framework::position &start,framework::position &end)
{
    if(board.try_move_piece(start, end, current_player_turn)){
        current_player_turn = !current_player_turn;
    }
}

void Chess_game::game_status() const
{
    this->board.print_board();
    std::cout << "next turn: " << (char)((int) '0' + this->current_player_turn) << std::endl;
}
