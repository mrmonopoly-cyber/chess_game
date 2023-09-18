#include "Board.h"
#include "Board_cell.h"
#include <array>
#include <vector>

using namespace framework;

static bool default_board_peculiar_status_mantained()
{
    return true;
}

//public
template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::Board(const std::array<Piece,PIECE_TYPES> pieces_properties,
        const std::array<Player,N_PLAYER> player_list,
        const std::function<void(void)>default_board_configuration)
    :pieces_properties(pieces_properties),players(player_list),
    default_board_configuration(default_board_configuration),
    board_peculiar_status_mantained(default_board_peculiar_status_mantained)
{
    default_board_configuration();
}

template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::Board(const std::array<Piece,PIECE_TYPES> pieces_properties,
        const std::array<Player,N_PLAYER> player_list,
        const std::function<void(void)>default_board_configuration,
        const std::function<bool(void)>board_peculiar_status_mantained)
    :pieces_properties(pieces_properties),players(player_list),
    default_board_configuration(default_board_configuration),
    board_peculiar_status_mantained(board_peculiar_status_mantained)
{
    default_board_configuration();
}

template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
void Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::try_move_piece(position &start_position, position &end_position,
        const unsigned int player)
{
    Board_cell *start_cell;
    Board_cell *dest_cell;
    Piece *start_piece;
    std::vector<struct position> *context_to_check;
    unsigned int vector_size;
       
    //cells
    start_cell = find_cell(start_position);
    if(!start_cell){
        return;
    }
    dest_cell = find_cell(end_position);
    if(!dest_cell)
    {
        return;
    }
    
    //piece
    start_piece = find_piece_category(start_cell->get_type());
    if(!start_piece){
        return;
    }

    //position to check   
    context_to_check = start_piece->context_to_check(start_position,end_position);
    vector_size = context_to_check->size();

    //cells to check
    const struct framework::Board_cell *cell_to_check[vector_size];
    for(int i =0; i < vector_size;i++)
    {
        cell_to_check[i] = find_cell(context_to_check[i]);
    }
    
    //checking fase
    if(start_piece->valid_move(cell_to_check,vector_size) && board_peculiar_status_mantained())
    {
        //moving piece
        dest_cell->overwrite(*start_cell);
        dest_cell->reset();
    }

    //free the memory
    context_to_check->clear();
    context_to_check->shrink_to_fit();
    delete context_to_check;
}

template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
void Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::reset_board()
{
    for(struct Board_cell &b : this->board)
    {
        b.reset();
    }
    default_board_configuration();
}

template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
void Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::print_board() const
{
    unsigned int cursor = 0;
    for(const Board_cell & cell : board){
        std::cout << cell << " ";
        cursor++;
        if(cursor == SIDE_H){
            std::cout << std::endl;
            cursor =0;
        }
    }
}

//private
template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
Board_cell *Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::find_cell(const struct position &pos)const
{
    const unsigned int index = pos.x + (pos.y * SIDE_V);   
    if(index >= 0 && index < (SIDE_H * SIDE_V))
    {
        return nullptr;
    }

    return &board[index];
}

template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
const Piece *Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::find_piece_category(const std::string &piece_type)
{
    if(piece_type.empty()){
        return nullptr;
    }
    for(const Piece *p : pieces_properties)
    {
        if(*(*p).piece_name() == piece_type){
            return p;
        }
    }
    return nullptr;
}
