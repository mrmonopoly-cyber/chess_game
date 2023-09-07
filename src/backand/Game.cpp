#include "Game.h"

#include <vector>

#include "Piece.h"

using namespace backand;

Game::Game() {
  this->board_size = 8;
  this->board = new struct piece_in_board[board_size * board_size];
  this->Pieces_properties.push_back(new Pawn());
  this->Pieces_properties.push_back(new Knight());
  this->Pieces_properties.push_back(new Bishop());
  this->Pieces_properties.push_back(new Rook());
  this->Pieces_properties.push_back(new Queen());
  this->Pieces_properties.push_back(new King());
}

Game::Game(unsigned int board_size) {
  this->board_size = board_size;
  this->board = new struct piece_in_board[board_size * board_size];
}

Game::~Game() { this->Pieces_properties.clear(); }

unsigned int Game::position_in_board(position &position) {
  int res = position.x * board_size;
  return res + position.y;
}
void Game::try_move_piece(position &start_position, position &end_position) {
  unsigned int pos_start = position_in_board(start_position);
  unsigned int pos_end = position_in_board(end_position);
  piece_in_board start_position_info = board[pos_start];
  piece_in_board end_position_info = board[pos_end];
  bool attacking = false;
  if (start_position_info.color != end_position_info.color) {
    attacking = true;
  }
  Piece *to_move = nullptr;
  switch (start_position_info.type) {
    case PAWN:
      to_move = this->Pieces_properties.at(0);
      break;
    case KNIGHT:
      to_move = this->Pieces_properties.at(1);
      break;
    case BISHOP:
      to_move = this->Pieces_properties.at(2);
      break;
    case ROOK:
      to_move = this->Pieces_properties.at(3);
      break;
    case QUEEN:
      to_move = this->Pieces_properties.at(4);
      break;
    case KING:
      to_move = this->Pieces_properties.at(5);
      break;
    default:
      return;
      break;
  }

  if (to_move == nullptr) {
    return;
  }

  if (attacking) {
    if (to_move->attack_move_no_context(start_position, end_position)) {
      // check context and then move
    }
    return;
  }
  if (to_move->normal_move_no_context(start_position, end_position) ||
      to_move->special_move_no_context(start_position, end_position)) {
    // check context and then move
  }
  return;
}
