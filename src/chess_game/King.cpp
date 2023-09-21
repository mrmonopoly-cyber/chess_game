#include <algorithm>
#include <cmath>
#include <vector>
#include "include/chess_game/Chess_pieces.h"

using namespace chess;
King::King() : chess::Generic_chess_piece("King")
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
    int increment_x =-1;
    if(abs(diff_x) == 2 && !diff_y){
        std::vector<struct framework::position> *res = 
            new std::vector<struct framework::position>(0);
        if(diff_x > 0){
            increment_x=1;
        }
        int i =0;
        for(i=0;i<=abs(diff_x)+1;i++)
        {
            res->emplace_back(framework::position{start_position.x + (increment_x * i),
                    start_position.y});
        }
        if(diff_x < 0){
            res->emplace_back(framework::position{start_position.x + (increment_x * i),
                    start_position.y});
        }
        return res;
    }
    return Generic_chess_piece::context_to_check(start_position, end_position,owner );
}

bool King::valid_move(const std::vector<framework::Board_cell> & context_array,
        std::vector<struct framework::position> *positions,
        std::vector<framework::cell_configuration> &out_secondary_effect)const 
{
    unsigned int c_size = context_array.size();
    unsigned int i=0;
    //castle 
    if(c_size==4 || c_size==5){
        if(context_array[0].get_type() == this->name && context_array[0].no_moved()){

            for(i=1;i<c_size-1;i++){
                if(!context_array[i].is_empty()){
                    return false;
                }
            }
            if(context_array[i].get_type() != "Rook" || !context_array[i].no_moved()){
                return false;
            }
        }
        //secondary effect of castle

        framework::position & future_rook_pos = positions->at(1);
        framework::position & old_rook_pos = positions->at(c_size - 1);
        out_secondary_effect.push_back(
                {
                    future_rook_pos.x,
                    future_rook_pos.y,
                    3,  //warning to change in board_cell.h from index to name of the piece
                    context_array[0].get_owner()
                });
        out_secondary_effect.push_back(
                {
                    old_rook_pos.x,
                    old_rook_pos.y,
                    -1,  //warning to change in board_cell.h from index to name of the piece
                    context_array[0].get_owner()
                });

        return true;
    }
    return Generic_chess_piece::valid_move(context_array,positions,out_secondary_effect);
}
