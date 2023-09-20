#include <algorithm>
#include <cmath>
#include <vector>
#include "Chess_pieces.h"
#include "include/chess_game/Chess_pieces.h"

using namespace chess;
King::King() : framework::Piece("King")
{
    //ok to be empty
}
King::~King() 
{
    //ok to be empty
}

std::vector<struct framework::position> *King::context_to_check(
        framework::position &start_position, framework::position &end_position,
        const unsigned int owner)const 
{
    const int diff_x = ((int) end_position.x - (int)start_position.x);
    const int diff_y = ((int) end_position.y - (int)start_position.y);
    int increment_x = -1;
    int increment_y = -1;
    if(diff_x > 1 || diff_y > 1){
        return nullptr;
    }
    if(diff_x > 0){
        increment_x = 1;
    }
    if (diff_y > 0) {
        increment_y = 1;
    }
    if(vertical_check(start_position, end_position)){
        increment_x = 0;
    }else if (horizontal_check(start_position,end_position)) {
        increment_y = 0;
    }else if(diagonal_check(start_position, end_position)){
        //ok to be empty
    }else {
        return nullptr;
    }

    std::vector<framework::position> *res = new std::vector<framework::position>(0);
    for(int i=1;i<std::max(abs(diff_x),abs(diff_y));i++)
    {
        res->emplace_back(framework::position{start_position.x + (increment_x * i),start_position.y + (increment_y *i)});
    }
    return res;
}
bool King::valid_move(const std::vector<framework::Board_cell> &context_array,
        std::vector<struct framework::position> *positions,
        const unsigned int size)const 
{
    if(context_array.empty()){
        return false;
    }

    if(context_array.at(0).get_type() != "King"){
        return false;
    }

    for(int i=1;i<size;i++){
        if(!context_array.at(i).is_empty()){
            return false;
        }
    }

    return true;
}
