#include <vector>
#include "include/chess_game/Chess_pieces.h"

using namespace chess;
using namespace framework;

Knight::Knight():Piece(3,"Knight")
{
    //ok to be empty
}

std::vector<struct position> *Knight::context_to_check(
        position &start_position, position &end_position,
        const unsigned int owner)const
{
    if(l_movement(start_position, end_position))
    {
        std::vector<struct position> *res = new std::vector<struct position>(2);
        res->emplace_back(start_position);
        res->emplace_back(end_position);
        return res;
    }
    return nullptr;
}

bool Knight::valid_move(const struct framework::Board_cell ** context_array,
        std::vector<struct framework::position> *positions,
        const unsigned int size)const
{
    if(!context_array){
        return false;
    }
    
   const Board_cell *start_cell = &context_array[0][0];
    const Board_cell *end_cell = &context_array[0][1];
    
    return 
        start_cell->get_type() == "Knight" &&
        (end_cell->is_empty() || start_cell->get_owner() != end_cell->get_owner()  );
}


bool Knight::l_movement(framework::position &start_position, framework::position &end_position) const
{
    const unsigned int diff_x = abs((int)start_position.x - (int)end_position.x);
    const unsigned int diff_y = abs((int)start_position.y - (int)end_position.y);
    return !diff_x && !diff_y && !(this->range - diff_x - diff_y);
}
