#include "Game.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

#include "Piece.h"

using namespace backand;
// public
Game::Game()
    : side_length(default_size),
      board(new board_cell[default_size * default_size]) {
  pieces_properties.reserve(6);
  pieces_properties.emplace_back(Pawn());
  pieces_properties.emplace_back(Knight());
  pieces_properties.emplace_back(Bishop());
  pieces_properties.emplace_back(Rook());
  pieces_properties.emplace_back(Queen());
  pieces_properties.emplace_back(King());

  // set Pawns
  for (int i = 0; i < default_size; i++) {
    // BLACK Pawns
    put_piece_on_board(*pieces_properties[0]->piece_name(), Piece::BLACK,
                       default_size + i);
    // WHITE Pawns
    put_piece_on_board(*pieces_properties[0]->piece_name(), Piece::WHITE,
                       (6 * default_size) + i);
  }
  // BLACK Rook
  put_piece_on_board(*pieces_properties[3]->piece_name(), Piece::BLACK, 0);
  put_piece_on_board(*pieces_properties[3]->piece_name(), Piece::BLACK, 7);
  // WHITE Rook
  put_piece_on_board(*pieces_properties[3]->piece_name(), Piece::WHITE,
                     (7 * default_size) + 0);
  put_piece_on_board(*pieces_properties[3]->piece_name(), Piece::WHITE,
                     (7 * default_size) + 7);
  // BLACK Knight
  put_piece_on_board(*pieces_properties[1]->piece_name(), Piece::BLACK, 1);
  put_piece_on_board(*pieces_properties[1]->piece_name(), Piece::BLACK, 6);
  // WHITE Knight
  put_piece_on_board(*pieces_properties[1]->piece_name(), Piece::BLACK,
                     (7 * default_size) + 1);
  put_piece_on_board(*pieces_properties[1]->piece_name(), Piece::BLACK,
                     (7 * default_size) + 6);
  // BLACK Bishop
  put_piece_on_board(*pieces_properties[2]->piece_name(), Piece::BLACK, 2);
  put_piece_on_board(*pieces_properties[2]->piece_name(), Piece::BLACK, 5);
  // WHITE Bishop
  put_piece_on_board(*pieces_properties[2]->piece_name(), Piece::WHITE,
                     (7 * default_size) + 2);
  put_piece_on_board(*pieces_properties[2]->piece_name(), Piece::WHITE,
                     (7 * default_size) + 5);
  // BLACK Queen
  put_piece_on_board(*pieces_properties[4]->piece_name(), Piece::BLACK, 3);
  put_piece_on_board(*pieces_properties[4]->piece_name(), Piece::WHITE,
                     (7 * default_size) + 3);
  // BLACK King
  put_piece_on_board(*pieces_properties[5]->piece_name(), Piece::BLACK, 4);
  put_piece_on_board(*pieces_properties[5]->piece_name(), Piece::WHITE,
                     (7 * default_size) + 4);
}

Game::Game(unsigned int board_size,
           const std::vector<std::shared_ptr<Piece>> pieces_properties)
    : board(new board_cell[board_size * board_size]),
      side_length(board_size),
      pieces_properties(pieces_properties) {}

Game::~Game() {
  this->pieces_properties.clear();
  this->pieces_properties.shrink_to_fit();
  delete[] this->board;
}

void Game::try_move_piece(position &start_position, position &end_position) {
  const unsigned int start_index_in_board = position_in_board(start_position);
  const unsigned int end_index_in_board = position_in_board(end_position);
  board_cell &start_cell = board[start_index_in_board];
  board_cell &end_cell = board[end_index_in_board];
  std::shared_ptr<Piece> start_piece;
  std::shared_ptr<Piece> end_piece;

  start_piece = find_piece_type(start_cell.piece_type);
  if (start_piece != nullptr) {
    end_piece = find_piece_type(end_cell.piece_type);
    if (end_piece != nullptr) {
      if (start_cell.color != end_cell.color &&
          start_piece->attack_move_no_context(start_position, end_position)) {
        move_piece_in_board(start_cell, end_cell);
      }
    } else if (start_piece->normal_move_no_context(start_position,
                                                   end_position)) {
      move_piece_in_board(start_cell, end_cell);
    }
  }
}

void Game::print_board() const {
  unsigned int index_board;
  for (int i = 0; i < this->side_length; i++) {
    for (int j = 0; j < this->side_length; j++) {
      index_board = (i * this->side_length) + j;
      if (this->board[index_board].color == Piece::BLACK) {
        std::cout << "B";
      } else {
        std::cout << "W";
      }
      std::cout << this->board[index_board].piece_type << "\t";
    }
    std::cout << std::endl;
  }
}
// private
void Game::move_piece_in_board(struct board_cell &start,
                               struct board_cell &end) {
  end.piece_type = start.piece_type;
  end.color = start.color;
  start.piece_type.clear();
}
void Game::put_piece_on_board(const std::string piece_name,
                              const Piece::PIECE_COLOR color,
                              const unsigned int pos) const {
  this->board[pos].piece_type = piece_name;
  this->board[pos].color = color;
}

std::shared_ptr<Piece> Game::find_piece_type(const std::string &type) {
  if (type.empty()) {
    return nullptr;
  }
  std::cout << "type input: " << type << std::endl;
  for (std::shared_ptr<Piece> p : this->pieces_properties) {
    std::cout << "in for each: " << *p->piece_name() << std::endl;
    if (*p->piece_name() == type) {
      return p;
    }
  }
  return nullptr;
}
unsigned int Game::position_in_board(position &start_position) const {
  unsigned int first_dimension = start_position.x * this->side_length;
  unsigned int second_dimension = start_position.y;
  return first_dimension + second_dimension;
}

int main(int argc, char *argv[]) {
  Game game;
  struct position start = {1, 0};
  struct position end = {2, 0};
  game.try_move_piece(start, end);
  game.print_board();
  return 0;
}
