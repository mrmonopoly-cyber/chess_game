#include "Board.h"

using namespace framework;

template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER>
Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER>::Board(const std::array<Piece,PIECE_TYPES> pieces_properties,
        const std::vector<Player> player_list,
        const std::function<void(void)>default_board_configuration)
    :pieces_properties(pieces_properties),players(player_list),default_board_configuration(default_board_configuration)
{
    default_board_configuration();
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


