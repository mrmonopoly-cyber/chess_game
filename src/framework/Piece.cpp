#include "include/framework/Piece.h"
#include <cstdlib>
#include <string>

using namespace framework;

//public
//constructor and deconstructor
Piece::Piece(const std::string &name)
    :name(name)
{
    //ok to be empty
}

Piece::~Piece()
{
    //ok to be empty
}
//functions

const std::string &Piece::piece_name() const
{
    return name;
}

