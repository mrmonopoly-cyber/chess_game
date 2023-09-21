#include "Board_cell.h"
#include <iostream>
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

const std::string &Board_cell::get_type() const
{
    return this->piece_type;
}

void Board_cell::overwrite(Board_cell &cell) 
{
    this->piece_type = cell.piece_type;
    this->owner = cell.owner;
    this->never_moved = false;
}

void Board_cell::put_piece(const std::string &piece_name, const unsigned int owner)
{
    this->piece_type = piece_name;
    this->owner = owner;
    this->never_moved = true;
}

bool Board_cell::is_empty()const
{
    return this->piece_type.empty();
}


bool Board_cell::no_moved() const
{
    return this->never_moved;
}

std::ostream& framework::operator<<(std::ostream &stream, const framework::Board_cell &board_cell)
{
    stream << board_cell.piece_type << board_cell.owner;

    return stream;
}
