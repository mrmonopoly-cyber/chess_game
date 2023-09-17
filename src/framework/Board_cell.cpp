#include "Board_cell.h"
#include <string>

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

unsigned int Board_cell::get_owner() const
{
    return this->owner;
}

std::string &Board_cell::get_type() 
{
    return this->piece_type;
}


void Board_cell::overwrite(Board_cell &cell) 
{
    this->piece_type = cell.piece_type;
    this->owner = cell.owner;
    this->never_moved = false;
}

std::ostream& framework::operator<<(std::ostream &stream, const framework::Board_cell &board_cell)
{
    stream << board_cell.piece_type << board_cell.owner;

    return stream;
}
