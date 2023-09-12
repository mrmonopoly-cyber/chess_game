#include <cstdlib>

#include "Piece.h"

using namespace backand;

// Pawn Piece
Pawn::Pawn() : Piece(1, "Pawn") {}
Pawn::~Pawn() {}

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
                                   position const &end_position) {
  return false;
}
// Pawn Piece end
// Knight Piece
Knight::Knight() : Piece(3, "Knight") {}
Knight::~Knight() {}

bool Knight::l_movement(const position &start_position,
                        const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - end_position.x);
  unsigned int diff_y = abs(start_position.y - end_position.y);
  return diff_x && diff_y && !(diff_x + diff_y - this->range);
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
                                   position const &end_position) {
  return false;
}
// King Piece end
