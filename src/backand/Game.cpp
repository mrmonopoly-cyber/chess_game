#include "Game.h"

#include "Piece.h"

using namespace backand;

void Game::create_pieces() {
  Pieces_properties[0] = new Pawn();
  Pieces_properties[1] = new Pawn();
  Pieces_properties[2] = new Pawn();
  Pieces_properties[3] = new Pawn();
  Pieces_properties[4] = new Pawn();
  Pieces_properties[5] = new Pawn();
  Pieces_properties[6] = new Pawn();
}

Game::Game() {
  this->board_size = 8;
  this->Pieces_properties = new Piece[board_size];
  this->board = new struct piece_in_board[board_size * board_size];
}

Game::Game(unsigned int board_size) {
  this->board_size = board_size;
  this->Pieces_properties = new Piece[board_size];
  this->board = new struct piece_in_board[board_size * board_size];
}

Game::~Game() {
  for (int i = 0; i < 8; ++i) {
    this->Pieces_properties[i].~Piece();
  }
  delete Pieces_properties;
  delete this->board;
}

unsigned int Game::position_in_board(position &position) {
  int res = position.x * board_size;
  return res + position.y;
}
void Game::try_move_piece(position &start_position, position &end_position) {
  unsigned int pos = position_in_board(start_position);
  piece_in_board position_info = board[pos];
  Piece to_move;
  switch (position_info.type) {
    case PAWN:
      to_move =
  }
}
