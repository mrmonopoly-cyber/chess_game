#include <cmath>

#include "Piece.h"

using namespace backand;

enum piece_movement {
  VERTICAL = (1 << 0),
  HORIZONTAL = (1 << 1),
  DIAGONAL = (1 << 2),
  L_MOVE = (1 << 3),
  ONLY_UP = (1 << 4)
};

bool valid_move(unsigned int movement, unsigned int range,
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

Piece::~Piece() { delete this; }

class Pawn : protected Piece {
  Pawn() : Piece::Piece(PAWN, VERTICAL | ONLY_UP, DIAGONAL | ONLY_UP, 1){};
  bool special_move_no_context(position &start_position,
                               position &end_position) {
    return false;
  }
};

class Knight : protected Piece {
  Knight() : Piece::Piece(KNIGHT, L_MOVE, 0, 3){};
};

class Bishop : protected Piece {
  Bishop() : Piece::Piece(BISHOP, DIAGONAL, 0, -1){};
};

class Rook : protected Piece {
  Rook() : Piece::Piece(ROOK, VERTICAL | HORIZONTAL, 0, -1){};
};

class Queen : protected Piece {
  Queen() : Piece::Piece(QUEEN, VERTICAL | HORIZONTAL | DIAGONAL, 0, -1){};
};

class King : protected Piece {
  King() : Piece::Piece(KING, VERTICAL | HORIZONTAL | DIAGONAL, 0, 1){};
  bool special_move_no_context(position &start_position,
                               position &end_position) {
    return false;
  }
};
