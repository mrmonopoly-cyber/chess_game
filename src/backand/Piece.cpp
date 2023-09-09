#include "Piece.h"

#include <cstdlib>
#include <string>

using namespace backand;

Piece::Piece(const char *const name) : range(0), name(name) {}
Piece::Piece(const int range, const char *const name)
    : range(range), name(name) {}
Piece::~Piece(){};
std::string *Piece::piece_name() const { return new std::string(this->name); }

bool Piece::vertical_check(const position &start_position,
                           const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - start_position.x);
  unsigned int diff_y = abs(start_position.y - start_position.y);
  if (!diff_x) {
    return diff_y - (this->range - 1);
  }
  return false;
}

bool Piece::horizontal_check(const position &start_position,
                             const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - start_position.x);
  unsigned int diff_y = abs(start_position.y - start_position.y);
  if (!diff_y) {
    return diff_x - (this->range - 1);
  }
  return false;
}

bool Piece::diagonal_check(const position &start_position,
                           const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - start_position.x);
  unsigned int diff_y = abs(start_position.y - start_position.y);

  if (diff_x == diff_y) {
    return diff_y - (this->range - 1);
  }

  return false;
}
bool Piece::normal_move_no_context(const position &start_position,
                                   const position &end_position) {
  return false;
}
bool Piece::attack_move_no_context(const position &start_position,
                                   const position &end_position) {
  return false;
}
bool Piece::special_move_no_context(const position &start_position,
                                    const position &end_position) {
  return false;
}
