#include "Piece.h"

Piece::Piece(PIECE_TYPE type, unsigned int piece_direction) {
  this->type = type;
  this->piece_direction = piece_direction;
}

Piece::~Piece() { delete this; }
