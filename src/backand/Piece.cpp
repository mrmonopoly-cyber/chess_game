#include "Piece.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace backand;
Piece::Piece(const char *const name) : range(0), name(name) {}
Piece::Piece(const int range, const char *const name)
    : range(range), name(name) {}

Piece::Piece(const int range, const char *const name, bool jump_pieces)
    : range(range), name(name), jump_pieces(jump_pieces){};
Piece::~Piece(){};
std::string *Piece::piece_name() const { return new std::string(this->name); }

bool Piece::vertical_check(const position &start_position,
                           const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - end_position.x);
  unsigned int diff_y = abs(start_position.y - end_position.y);
  if (!diff_x) {
    return diff_y - (this->range - 1);
  }
  return false;
}

bool Piece::horizontal_check(const position &start_position,
                             const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - end_position.x);
  unsigned int diff_y = abs(start_position.y - end_position.y);
  if (!diff_y) {
    return diff_x - (this->range - 1);
  }
  return false;
}

bool Piece::diagonal_check(const position &start_position,
                           const position &end_position) const {
  unsigned int diff_x = abs(start_position.x - end_position.x);
  unsigned int diff_y = abs(start_position.y - end_position.y);

  if (diff_x == diff_y) {
    return diff_y - (this->range - 1);
  }

  return false;
}
std::vector<struct position> *context_to_check_normal_move(
      position &start_position, position &end_position){
    return nullptr;
}
std::vector<struct position> *context_to_check_special_move(
          const position &start_position,const position &end_position){
    return nullptr;
}

bool Piece::normal_move_no_context(const position &start_position,
                                   const position &end_position) {
  std::cout << "default operation " << std::endl;
  return false;
}
bool Piece::attack_move_no_context(const position &start_position,
                                   const position &end_position) {
  std::cout << "default operation " << std::endl;
  return false;
}
bool Piece::special_move_no_context(const position &start_position,
                                    const position &end_position,
                                    const std::vector<struct position> context) {
  std::cout << "default operation " << std::endl;
  return false;
}
