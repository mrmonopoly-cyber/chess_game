#include <vector>
#include <cstdlib>
#include "include/chess_game/Chess_pieces.h"

using namespace chess;
using namespace framework;

Pawn::Pawn() : framework::Piece(1,"Pawn")
{
    //ok to be empty
}

std::vector<struct framework::position> *Pawn::context_to_check(
        framework::position &start_position, framework::position &end_position,
        const unsigned int owner)const
{
    const unsigned int diff_x =abs((int)start_position.x - (int)end_position.x); 
    const unsigned int diff_y =abs((int)start_position.y - (int)end_position.y); 
    //double push
    if(diff_y == 2 && !diff_x){
        std::vector<struct position> *res = new std::vector<struct position>(3);
        res->emplace_back(start_position);
        if(owner){
            res->emplace_back(new position{start_position.x,start_position.y-1});
        }else {
            res->emplace_back(new position{start_position.x,start_position.y+1});
        }
        res->emplace_back(end_position);
        return res;
    }
    //single push
    if(diff_y == 1 && !diff_x)
    {
        std::vector<struct position> *res = new std::vector<struct position>(2);
        res->emplace_back(start_position);
        res->emplace_back(end_position);
        return res;
    }
    return nullptr;
}

bool Pawn::valid_move(const struct framework::Board_cell ** context_array,
        std::vector<struct framework::position> positions,
        const unsigned int size)const 
{
    if(!context_array || context_array[0][0].get_type()!="Pawn"){
        return false;
    }
    //single push ,attack normal
    if(size == 2){
        return 
            //single push
            (context_array[0][1].is_empty() &&
                positions[0].x == positions[1].x) ||
            //attack normal
            (positions[0].x != positions[1].x &&
             context_array[0][0].get_owner() != context_array[0][1].get_owner());
    }
    //double push
    if(size==3){
        return 
            context_array[0][0].no_moved() &&
            context_array[0][1].is_empty() &&
            context_array[0][2].is_empty() &&
            positions[0].x == positions[2].x;
    }
    return false;
}

