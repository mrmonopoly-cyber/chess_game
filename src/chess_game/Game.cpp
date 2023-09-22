#include "include/chess_game/Game.h"
#include "Game.h"
#include "include/chess_game/Chess_pieces.h"
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
    find_piece_position("King",!player,pos);
    int increment_x =0;
    int increment_y =1;
    //horizontal
    if(find_enemy_piece(pos,0,1,player) || find_enemy_piece(pos,0,-1,player)){
        return false;
    }
    //vertical
     if(find_enemy_piece(pos,1,0,player) || find_enemy_piece(pos,-1,0,player)){
        return false;
    }

    //diagonal 
    if(
            find_enemy_piece(pos,1,1,player) || 
            find_enemy_piece(pos,-1,1,player) ||
            find_enemy_piece(pos,1,-1,player) ||
            find_enemy_piece(pos,-1,-1,player)
      ){
        return false;
    }
    //knight

    // std::cout << "new search\n";
    // std::cout << pos.x << "," << pos.y << std::endl;
    return true;
}
bool Chess_board::find_enemy_piece(position &start_position, const int increment_x,
        const int increment_y,const unsigned int owner) const
{
    const Board_cell *king_cell = find_cell(start_position);
    position enemy;
    const Board_cell *enemy_cell;
    const Piece *enemy_piece;
    vector<struct position> *context_to_check;
    vector<Board_cell> pc = vector<Board_cell>(0);
    vector<cell_configuration> secondary_effect;
    unsigned int vector_size;

    while (enemy.x < SIDE_H && enemy.y < SIDE_V 
            && enemy.x > 0 && enemy.y>0) {
        enemy_cell = find_cell(enemy);
        if(enemy_cell->get_owner() != owner && !enemy_cell->is_empty()){
            enemy_piece = find_piece_category(enemy_cell->get_type());
            context_to_check = enemy_piece->context_to_check(start_position,enemy,owner);
            if(context_to_check){
                vector_size = context_to_check->size();
                //cells to check
                if(vector_size){
                    for(int i =0; i < vector_size;i++)
                    {
                        const Board_cell *b = find_cell(context_to_check->at(i));
                        if(!b)
                        {
                            context_to_check->clear();
                            context_to_check->shrink_to_fit();
                            delete context_to_check;
                            return false;
                        }
                        pc.push_back(*b);
                    }
                }
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
