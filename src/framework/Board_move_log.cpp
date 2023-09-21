#include "include/framework/Board_move_log.h"

using namespace framework;

Board_move_log::Board_move_log()
{
    //ok to be empty
}

void Board_move_log::insert(const Log & move)
{
    history.push_back(move);
}


const Board_move_log::Log *Board_move_log::last_move() const
{
    unsigned int last = history.size()-1;
    return last_ith_move(last);
}


const Board_move_log::Log *Board_move_log::last_ith_move(unsigned int i) const
{
    return &history[i];
}
