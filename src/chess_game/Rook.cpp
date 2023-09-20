#include <algorithm>
#include <cmath>
#include <vector>
#include "include/chess_game/Chess_pieces.h"

using namespace chess;

Rook::Rook() : chess::Generic_chess_piece("Rook")
{
    //ok to be empty
}
Rook::~Rook() 
{
    //ok to be empty
}

bool Rook::increment_conf(const int diff_x, const int diff_y,
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
    return false;
}


