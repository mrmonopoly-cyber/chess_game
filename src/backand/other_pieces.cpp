#include <cstdlib>
#include <vector>

#include "Piece.h"

using namespace backand;
//common private functions
static std::vector<struct position>* position_array(const int diff_x, const unsigned int increment_x, 
        const unsigned int increment_y,const struct position &position) {
    std::vector<struct position>* res = new std::vector<struct position>(abs(diff_x)-1);
    for (unsigned int i = 0; i < abs(diff_x) - 1; i++) {
        (*res)[i].x = position.x + (increment_x * (i + 1));
        (*res)[i].y = position.y + (increment_y * (i + 1));
    }
    return res;
}


// Pawn Piece
Pawn::Pawn() : Piece(1, "Pawn") {}
Pawn::~Pawn() {}

std::vector<struct position>* Pawn::context_to_check_normal_move(
        position &start_position, position &end_position) {
    return new std::vector<struct position>(0);
}

std::vector<struct position>* Pawn::context_to_check_special_move(
        const position &start_position, const position &end_position) {
    std::vector<struct position>* res = new std::vector<struct position>(3);
    

    return res;
}
bool Pawn::normal_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position);
}

bool Pawn::attack_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::diagonal_check(start_position, end_position);
}

// todo : implement first move_double_push
bool Pawn::special_move_no_context(position const &start_position,
        position const &end_position, const std::vector<struct position> context) {
    return false;
}
// Pawn Piece end
// Knight Piece
Knight::Knight() : Piece(3, "Knight", true) {}
Knight::~Knight() {}

bool Knight::l_movement(const position &start_position,
        const position &end_position) const {
    unsigned int diff_x = abs(start_position.x - end_position.x);
    unsigned int diff_y = abs(start_position.y - end_position.y);
    return diff_x && diff_y && !(diff_x + diff_y - this->range);
}
std::vector<struct position>* Knight::context_to_check_normal_move(
        position &start_position, position &end_position) {
    return new std::vector<struct position>(0);
}

bool Knight::normal_move_no_context(const position &start_position,
        const position &end_position) {
    return l_movement(start_position, end_position);
}

bool Knight::attack_move_no_context(const position &start_position,
        const position &end_position) {
    return l_movement(start_position, end_position);
}
// Knight Piec end
// Bishop Piece
Bishop::Bishop() : Piece("Bishop") {}
Bishop::~Bishop() {}

std::vector<struct position>* Bishop::context_to_check_normal_move(
        position &start_position, position &end_position) {
    int diff_x = end_position.x - start_position.x;
    int diff_y = end_position.y - start_position.y;
    int increment_x = -1;
    int increment_y = -1;

    if (diff_x > 0) {
        increment_x = 1;
    }
    if (diff_y > 0) {
        increment_y = 1;
    }
    return position_array(diff_x, increment_x, increment_y, start_position);
}

bool Bishop::normal_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::diagonal_check(start_position, end_position);
}

bool Bishop::attack_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::diagonal_check(start_position, end_position);
}
// Bishop Piece end
// Rook Piece
Rook::Rook() : Piece("Rook") {}
Rook::~Rook() {}

std::vector<struct position>* Rook::context_to_check_normal_move(
        position &start_position, position &end_position) {
    int diff_x = end_position.x - start_position.x;
    int diff_y = end_position.y - start_position.y;
    int diff_to_use;
    int increment_x = -1;
    int increment_y = -1;

    if (diff_x > 0) {
        increment_x = 1;
        increment_y = 0;
        diff_to_use=diff_x;
    }
    if (diff_y > 0) {
        increment_x = 0;
        increment_y = 1;
        diff_to_use=diff_y;
    }
    return position_array(diff_to_use, increment_x, increment_y, start_position);
}

bool Rook::normal_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position) ||
        Piece::horizontal_check(start_position, end_position);
}

bool Rook::attack_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position) ||
        Piece::horizontal_check(start_position, end_position);
}
// Rook Piece end
Queen::Queen() : Piece("Queen") {}
Queen::~Queen() {}

std::vector<struct position>* Queen::context_to_check_normal_move(
        position &start_position, position &end_position) {
    const int diff_x = end_position.x - start_position.x;
    const int diff_y = end_position.y - start_position.y;
    int diff_to_use = diff_x;
    int increment_x = -1;
    int increment_y = -1;
    
    if(!diff_x){
        increment_x=0;
        diff_to_use=diff_y;
    }
    if(!diff_y){
        increment_y=0;
        diff_to_use=diff_x;
    }
    if(diff_y > 0){
        increment_y=1;
    }
    if(diff_x > 0){
        increment_x =1;
    }
    return position_array(diff_to_use, increment_x, increment_y, start_position);
}

bool Queen::normal_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position) ||
        Piece::horizontal_check(start_position, end_position) ||
        Piece::diagonal_check(start_position, end_position);
}

bool Queen::attack_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position) ||
        Piece::horizontal_check(start_position, end_position) ||
        Piece::diagonal_check(start_position, end_position);
}
// Queen Piece end
// King Piece
King::King() : Piece(1, "King") {}
King::~King() {}

std::vector<struct position>* King::context_to_check_normal_move(
        position &start_position, position &end_position) {
    return new std::vector<position>(0);
}

bool King::normal_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position) ||
        Piece::horizontal_check(start_position, end_position) ||
        Piece::diagonal_check(start_position, end_position);
}

bool King::attack_move_no_context(const position &start_position,
        const position &end_position) {
    return Piece::vertical_check(start_position, end_position) ||
        Piece::horizontal_check(start_position, end_position) ||
        Piece::diagonal_check(start_position, end_position);
}

// todo : implement castle
bool King::special_move_no_context(position const &start_position,
        position const &end_position, const std::vector<struct position> context) {
    return false;
}
// King Piece end
