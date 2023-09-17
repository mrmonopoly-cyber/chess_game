#include "Board_cell.h"

using namespace framework;

Board_cell::Board_cell()
{
    //ok to be empty
}

void Board_cell::reset()
{
    piece_type.clear();
    owner=0;
    never_moved=true;
}

std::ostream& framework::operator<<(std::ostream &stream, const framework::Board_cell &board_cell)
{
    stream << board_cell.piece_type << board_cell.owner;

    return stream;
}
