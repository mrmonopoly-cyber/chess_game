#include <vector>
#include <cstdlib>
#include "include/chess_game/Chess_pieces.h"

using namespace chess;
using namespace framework;

Pawn::Pawn() : framework::Piece("Pawn")
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
        const unsigned int size)const 
{

}

