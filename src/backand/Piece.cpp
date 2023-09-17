#include "Piece.h"
#include <cstdlib>

using namespace backand;

//public
//constructor and deconstructor
Piece::Piece(const char *const name)
    :name(name)
{
    //ok to be empty
}

Piece::Piece(const unsigned int range, const std::string name)
    : range(range), name(name)
{
    //ok to be empty
}


Piece::Piece(const unsigned int range, const std::string name, const bool jump_pieces)
    : range(range), name(name), jump_pieces(jump_pieces)
{
    //ok to be empty
}

//functions
std::vector<struct position> * Piece::context_to_check(
        position &start_position, position &end_position)const
{
    return nullptr;
}

bool Piece::valid_move(const struct bacbackand::board_cell * context_array,
        const unsigned int size)const
{
    return false;
}

//protected
bool Piece::vertical_check(const position &start_position,
        const position &end_position) const
{
    const unsigned int diff_x = end_position.x - start_position.x;
    const unsigned int diff_y = end_position.y - start_position.y;
    if(!diff_x && this->range >= diff_y){
        return true;
    }
    return false;
}
bool Piece::horizontal_check(const position &start_position,
        const position &end_position) const
{
    const unsigned int diff_x = end_position.x - start_position.x;
    const unsigned int diff_y = end_position.y - start_position.y;
     if(!diff_y  && this->range >= diff_x){
        return true;
    }
    return false;

}
bool Piece::diagonal_check(const position &start_position,
        const position &end_position) const
{
    const unsigned int diff_x = end_position.x - start_position.x;
    const unsigned int diff_y = end_position.y - start_position.y;

    if(diff_x == diff_y && this->range>=diff_x){
        return true;
    }
    return false;
}


