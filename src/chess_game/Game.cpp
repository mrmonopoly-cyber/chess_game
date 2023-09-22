#include "include/chess_game/Game.h"
#include "Game.h"
#include "include/chess_game/Chess_pieces.h"
#include <algorithm>
#include <array>

using namespace chess;
using namespace framework;

//private implementation function
static const std::array<const Piece*,N_PIECE_TYPES> pieces_init()
{
    return
    {
        new Pawn(),
        new Knight(),
        new Bishop(),
        new Rook(),
        new Queen(),
        new King()
    };
}
static const std::array<const cell_configuration,N_INITIAL_PIECES> default_configuration(){
    const std::array<const Piece*,N_PIECE_TYPES> piece_list = pieces_init();
    return 
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
        //white pawn
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
        //white King
        4,7,piece_list[5]->piece_name(),0
    };
}

//Chess_board

Chess_board::Chess_board() : Board(pieces_init(),default_configuration())
{
    //ok to be empty
}

bool Chess_board::board_peculiar_status_maintained(const unsigned int player) const
{
    position pos;
    int i,j;
    find_piece_position("King",player,pos);
    
    //other pieces 
    for(i=-1;i<2;i++){
        for(j=-1;j<2;j++){
            if((i || j)  && find_enemy_piece(pos, i, j, player)){
                return false;
            }
        }       
    }
    //knight
    for(i=-2;i<3;i++){
        switch (abs(i)) {
            case 2:
                j=1;
                break;
            case 1:
                j=2;
                break;
            default:
                continue;
        }
        if(is_enemy_knight({pos.x + i, pos.y+j},player) ||
        is_enemy_knight({pos.x + i, pos.y+(-1 * j)},player)){
            return false;
        }
    }
    return true;
}
bool Chess_board::is_enemy_knight(position pos, const unsigned int player) const
{
    const Board_cell * cell;
    cell = find_cell(pos);
    return cell && cell->get_type() == "Knight" && cell->get_owner() != player;
}
bool Chess_board::find_enemy_piece(position &start_position, const int increment_x,
        const int increment_y,const unsigned int owner) const
{
    const Board_cell *king_cell = find_cell(start_position);
    position enemy = start_position;
    const Board_cell *enemy_cell;
    const Piece *enemy_piece;
    vector<struct position> *context_to_check;
    vector<Board_cell> pc = vector<Board_cell>(0);
    vector<cell_configuration> secondary_effect;

    enemy_cell = find_cell(enemy);
    pc.push_back(*enemy_cell);
    enemy.x+=increment_x;
    enemy.y+=increment_y;

    while (enemy.x < SIDE_H && enemy.y < SIDE_V 
            && enemy.x >= 0 && enemy.y >= 0) {
        enemy_cell = find_cell(enemy);
        pc.push_back(*enemy_cell);
        if(!enemy_cell->is_empty() && enemy_cell->get_owner() == owner){
            return false;
        }
        if(!enemy_cell->is_empty()){
            enemy_piece = find_piece_category(enemy_cell->get_type());
            context_to_check = enemy_piece->context_to_check(enemy,start_position,owner);
            if(context_to_check){
                std::reverse(pc.begin(),pc.end());
                if(enemy_piece->valid_move(pc,context_to_check, secondary_effect,
                            this->history)){
                    return true;
                }
            }
        }
        enemy.x+=increment_x;
        enemy.y+=increment_y;
    }
    return false;
}

//Game

//public
Chess_game::Chess_game() : board()
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
void Chess_game::move_piece(::position &start,::position &end)
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
