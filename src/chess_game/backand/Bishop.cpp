#include <cmath>
#include <vector>
#include "Chess_pieces.h"

using namespace chess;

Bishop::Bishop() : chess::Generic_chess_piece("Bishop")
{
    //ok to be empty
}
Bishop::~Bishop() 
{
    //ok to be empty
}

bool Bishop::increment_conf(const int diff_x, const int diff_y,
        int &increment_x, int &increment_y)const
{

    if(diff_x > 0){
        increment_x= 1;
    }
    if (diff_y > 0) {
        increment_y= 1;
    }
    if(diagonal_check(diff_x, diff_y)){
        return true;
    }
    return false;

}


