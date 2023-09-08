#include "Piece.h"

#include <cstdlib>

using namespace backand;

Piece::Piece(const int range) : range(range) {}

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
