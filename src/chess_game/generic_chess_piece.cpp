#include "generic_chess_piece.h"
#include "include/chess_game/Chess_pieces.h"

using namespace chess;

Generic_chess_piece::Generic_chess_piece(const std::string name)
    : range(0), framework::Piece(name)
{
    //ok to be empty
}

Generic_chess_piece::Generic_chess_piece(const unsigned int range, const std::string name)
    : range(range), framework::Piece(name)
{
    //ok to be empty
}

Generic_chess_piece::Generic_chess_piece(const unsigned int range, const bool jump, const std::string name)
    : range(range), jump_pieces(jump), framework::Piece(name)
{
    //ok to be empty
}

Generic_chess_piece::~Generic_chess_piece()
{
    //ok to be empty
}

bool Generic_chess_piece::valid_move(const std::vector<framework::Board_cell> & context_array,
        const std::vector<struct framework::position> *positions,
        std::vector<framework::cell_configuration> &out_secondary_effect,
        const framework::Board_move_log &log)const
{
    if(context_array.empty()){
        return false;
    }

    if(context_array.at(0).get_type() != this->name){
        return false;
    }
    
    int i=1;
    for(i=1;i<context_array.size()-1;i++){
        if(!context_array.at(i).is_empty()){
            return false;
        }
    }
    if(!context_array[i].is_empty() && context_array[i].get_owner() == context_array[0].get_owner()){
        return false;
    }

    return true;
}

bool Generic_chess_piece::increment_conf(const int diff_x, const int diff_y,
                                int &increment_x, int &increment_y)const
{
    if(diff_x > 0){
        increment_x= 1;
    }
    if (diff_y > 0) {
        increment_y= 1;
    }
    if(vertical_check(diff_x, diff_y)){
        increment_x= 0;
        return true;
    }
    if (horizontal_check(diff_x,diff_y)) {
        increment_y= 0;
        return true;
    }
    if(diagonal_check(diff_x, diff_y)){
        return true;
    }
    return false;
}

std::vector<struct framework::position> *Generic_chess_piece::context_to_check(
        framework::position &start_position, framework::position &end_position,
        const unsigned int owner)const 
{
    const int diff_x = ((int) end_position.x - (int)start_position.x);
    const int diff_y = ((int) end_position.y - (int)start_position.y);
    int increment_x =-1;
    int increment_y =-1;
    if(!increment_conf(diff_x,diff_y,increment_x,increment_y))
    {
        return nullptr;
    }
    std::vector<framework::position> *res = new std::vector<framework::position>(0);
    for(int i=0;i<=std::max(abs(diff_x),abs(diff_y));i++)
    {
        res->emplace_back(framework::position{start_position.x + (increment_x * i),
                start_position.y + (increment_y *i)});
    }
    return res;
}

bool Generic_chess_piece::vertical_check(const int diff_x, const int diff_y) const
{
    unsigned int a_diff_x = abs(diff_x);
    unsigned int a_diff_y = abs(diff_y);
    return !a_diff_x && a_diff_y - ((int)this->range -1);
}
bool Generic_chess_piece::horizontal_check(const int diff_x, const int diff_y) const
{
    unsigned int a_diff_x = abs(diff_x);
    unsigned int a_diff_y = abs(diff_y);
    return !a_diff_y && a_diff_x - ((int)this->range -1);
}
bool Generic_chess_piece::diagonal_check(const int diff_x, const int diff_y) const
{
    unsigned int a_diff_x = abs(diff_x);
    unsigned int a_diff_y = abs(diff_y);
    return a_diff_y == a_diff_x && a_diff_x - ((int)this->range -1);
}


