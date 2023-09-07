#include <cmath>
#include <cstddef>

#include "Piece.h"

using namespace backand;

bool Piece::valid_move(unsigned int movement, unsigned int range,
                       position &start_position, position &end_position) {
  int diff_x = std::abs(start_position.x - end_position.x);
  int diff_y = std::abs(start_position.y - end_position.y);

  switch (movement) {
    case L_MOVE:
      if ((diff_x == 2 && diff_y == 1) || (diff_x == 1 && diff_y == 2)) {
        return true;
      }
      break;
    case ONLY_UP &VERTICAL:
      if (diff_x == 0 && range == 1) {
        return true;
      }
      break;
    case VERTICAL:
      if (diff_x == 0) {
        return true;
      }
      break;
    case HORIZONTAL:
      if (diff_y == 0) {
        return true;
      }
      break;
    case DIAGONAL:
      if (diff_y == diff_x) {
        return true;
      }
  }
  return false;
}

Piece::Piece(PIECE_TYPE type, unsigned int movement, unsigned int attack,
             int range) {
  this->type = type;
  this->valid_movement = movement;
  this->valid_attack = attack;
  if (attack == 0) {
    this->valid_attack = movement;
  }
  this->range = range;
}

Piece::~Piece() { delete this; }
bool Piece::normal_move_no_context(position &start_position,
                                   position &end_position) {
  return valid_move(this->valid_movement, this->range, start_position,
                    end_position);
}

bool Piece::attack_move_no_context(position &start_position,
                                   position &end_position) {
  return valid_move(this->valid_attack, this->range, start_position,
                    end_position);
}

bool Piece::special_move_no_context(position &start_position,
                                    position &end_position) {
  return false;
}

// Pawn
Pawn::Pawn() : Piece(PAWN, VERTICAL | ONLY_UP, DIAGONAL | ONLY_UP, 1){};
bool Pawn::special_move_no_context(position &start_position,
                                   position &end_position) {
  return false;
}

// Knight
Knight::Knight() : Piece(KNIGHT, L_MOVE, 0, 3){};

// Bishop
Bishop::Bishop() : Piece::Piece(BISHOP, DIAGONAL, 0, -1){};

// Rook
Rook::Rook() : Piece::Piece(ROOK, VERTICAL | HORIZONTAL, 0, -1){};

// Queen
Queen::Queen() : Piece::Piece(QUEEN, VERTICAL | HORIZONTAL | DIAGONAL, 0, -1){};

// King
King::King() : Piece::Piece(KING, VERTICAL | HORIZONTAL | DIAGONAL, 0, 1){};
bool King::special_move_no_context(position &start_position,
                                   position &end_position) {
  return false;
}
