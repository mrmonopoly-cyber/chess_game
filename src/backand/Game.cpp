#include "Game.h"

#include <vector>

#include "Piece.h"

using namespace backand;

Game::Game()
    : side_length(default_size),
      board(new board_cell[default_size * default_size]) {
  pieces_properties.push_back(*new Pawn());
  pieces_properties.push_back(*new Knight());
  pieces_properties.push_back(*new Bishop());
  pieces_properties.push_back(*new Rook());
  pieces_properties.push_back(*new Queen());
  pieces_properties.push_back(*new King());
}

Game::Game(unsigned int board_size, const std::vector<Piece> pieces_properties)
    : board(new board_cell[board_size * board_size]),
      side_length(board_size),
      pieces_properties(pieces_properties) {}

Game::~Game() { this->pieces_properties.clear(); }

unsigned int Game::position_in_board(position &start_position) { return 0; }
