#include <cmath>
#include <valarray>

#include "Piece.h"

enum piece_movement {
  VERTICAL = (1 << 0),
  HORIZONTAL = (1 << 1),
  DIAGONAL = (1 << 2),
  L_MOVE = (1 << 3),
  ONLY_UP = (1 << 4)
};

enum PIECE_TYPE {
  NULL_PIECE = 0,
  PAWN = (1 << 0),
  KNIGHT = (1 << 1),
  BISHOP = (1 << 2),
  ROOK = (1 << 3),
  QUEEN = (1 << 4),
  KING = (1 << 5)
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
      if (range == 1) {
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

Piece::Piece(unsigned int type, unsigned int movement, int range) {
  this->type = type;
  this->valid_movement = movement;
  this->range = range;
}
Piece::~Piece() { delete this; }

class Pawn : protected Piece {
  Pawn() : Piece::Piece(PAWN, VERTICAL | ONLY_UP, 1){};
  bool normal_move_no_context(position &start_position,
                              position &end_position) {
    return false;
  }
};

class Knight : protected Piece {
  Knight() : Piece::Piece(KNIGHT, L_MOVE, 3){};
  bool normal_move_no_context(position &start_position,
                              position &end_position) {
    return true;
  }
};

class Bishop : protected Piece {
  Bishop() : Piece::Piece(BISHOP, DIAGONAL, -1){};
  bool normal_move_no_context(position &start_position,
                              position &end_position) {
    return true;
  }
};

class Rook : protected Piece {
  Rook() : Piece::Piece(ROOK, VERTICAL | HORIZONTAL, -1){};
  bool normal_move_no_context(position &start_position,
                              position &end_position) {
    return true;
  }
};

class Queen : protected Piece {
  Queen() : Piece::Piece(QUEEN, VERTICAL | HORIZONTAL | DIAGONAL, -1){};
  bool normal_move_no_context(position &start_position,
                              position &end_position) {
    return true;
  }
};

class King : protected Piece {
  King() : Piece::Piece(KING, VERTICAL | HORIZONTAL | DIAGONAL, 1){};
  bool normal_move_no_context(position &start_position,
                              position &end_position) {
    return true;
  }
};
