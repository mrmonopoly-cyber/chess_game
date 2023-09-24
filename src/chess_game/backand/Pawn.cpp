#include <vector>
#include <cstdlib>
#include "include/chess_game/backand/Chess_pieces.h"

using namespace chess;
using namespace framework;

Pawn::Pawn() : chess::Generic_chess_piece(1,"Pawn" )
{
    //ok to be empty
}

Pawn::~Pawn() 
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
        std::vector<struct position> *res = new std::vector<struct position>(0);
        res->emplace_back(start_position);
        if(!owner){
            res->emplace_back(position{start_position.x,start_position.y-1});
        }else {
            res->emplace_back(position{start_position.x,start_position.y+1});
        }
        res->emplace_back(end_position);
        return res;
    }
    //single push and diagonal attack
    if(diff_y == 1 && (!diff_x || diff_x == 1))
    {
        std::vector<struct position> *res = new std::vector<struct position>(0);
        res->emplace_back(start_position);
        res->emplace_back(end_position);
        return res;
    }
    return nullptr;
}

bool Pawn::valid_move(const std::vector<framework::Board_cell> &context_array,
        const std::vector<struct framework::position> *positions,
        std::vector<framework::cell_configuration> &out_secondary_effect,
        const framework::Board_move_log &log)const
{
    if(context_array.empty() || context_array.at(0).get_type()!="Pawn"){
        return false;
    }
    //single push ,attack normal
    if(context_array.size()== 2){
        const framework::Board_move_log::Log *last_move = log.last_move();
        if(
            //single push
            (context_array.at(1).is_empty() && positions->at(0).x == positions->at(1).x) ||
            //attack normal
            (positions->at(0).x != positions->at(1).x &&
             context_array.at(0).get_owner() != context_array.at(1).get_owner()))
        {
            return true;
        }
            //en Passant
            if(
            last_move->piece_type == "Pawn" && 
            last_move->start_x == last_move->dest_x &&
            (abs((int)last_move->start_y - (int)last_move->dest_y)) == 2 &&
            last_move->start_x == positions->at(1).x &&
            context_array.at(1).is_empty())
            {
                out_secondary_effect.push_back(
                        {
                            last_move->dest_x,
                            last_move->dest_y,
                            last_move->piece_type,
                            -1,
                        });
                return true;
            }
    }
    //double push
    if(context_array.size()==3){
        return 
            context_array.at(0).no_moved() &&
            context_array.at(1).is_empty() &&
            context_array.at(2).is_empty() &&
            positions->at(0).x == positions->at(2).x;
    }
    return false;
}

