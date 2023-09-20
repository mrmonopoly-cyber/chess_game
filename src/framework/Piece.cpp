#include "include/framework/Piece.h"
#include <cstdlib>

using namespace framework;

//public
//constructor and deconstructor
Piece::Piece(const char *const name)
    :name(name)
{
    //ok to be empty
}

Piece::Piece(const unsigned int range, const std::string name)
    : range(range), name(name)
{
    //ok to be empty
}


Piece::Piece(const unsigned int range, const std::string name, const bool jump_pieces)
    : range(range), name(name), jump_pieces(jump_pieces)
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
std::vector<struct position> * Piece::context_to_check(
        position &start_position, position &end_position,
        const unsigned int owner)const
{
    return nullptr;
}
bool Piece::valid_move(const std::vector<Board_cell> &context_array,
        std::vector<struct framework::position> *positions,
        const unsigned int size)const
{
    return false;
}

//protected
bool Piece::vertical_check(const position &start_position,
        const position &end_position) const
{
    const unsigned int diff_x = abs((int)end_position.x - (int)start_position.x);
    const unsigned int diff_y = abs((int)end_position.y - (int)start_position.y);
    return !diff_x && (diff_y - this->range) > 0;
}
bool Piece::horizontal_check(const position &start_position,
        const position &end_position) const
{
    const unsigned int diff_x = abs((int)end_position.x - (int)start_position.x);
    const unsigned int diff_y = abs((int)end_position.y - (int)start_position.y);
    return !diff_y && (diff_x - this->range) > 0;

}
bool Piece::diagonal_check(const position &start_position,
        const position &end_position) const
{
    const unsigned int diff_x = abs((int)end_position.x - (int)start_position.x);
    const unsigned int diff_y = abs((int)end_position.y - (int)start_position.y);
    return diff_x == diff_y && (diff_x - this->range) > 0;

}
