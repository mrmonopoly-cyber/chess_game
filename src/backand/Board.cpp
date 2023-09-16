#include "Board.h"

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>
using namespace backand;

// public
Board::Board()
    : side_length(default_size),
      board(new board_cell[default_size * default_size]) {
  pieces_properties.reserve(6);
  pieces_properties.emplace_back(new Pawn());
  pieces_properties.emplace_back(new Knight());
  pieces_properties.emplace_back(new Bishop());
  pieces_properties.emplace_back(new Rook());
  pieces_properties.emplace_back(new Queen());
  pieces_properties.emplace_back(new King());

  // set Pawns
  for (int i = 0; i < default_size; i++) {
    // 1 Pawns
    put_piece_on_board(*pieces_properties[0]->piece_name(), 1,
                       default_size + i);
    // 0 Pawns
    put_piece_on_board(*pieces_properties[0]->piece_name(), 0,
                       (6 * default_size) + i);
  }
  // 1 Rook
  put_piece_on_board(*pieces_properties[3]->piece_name(), 1, 0);
  put_piece_on_board(*pieces_properties[3]->piece_name(), 1, 7);
  // 0 Rook
  put_piece_on_board(*pieces_properties[3]->piece_name(), 0,
                     (7 * default_size) + 0);
  put_piece_on_board(*pieces_properties[3]->piece_name(), 0,
                     (7 * default_size) + 7);
  // 1 Knight
  put_piece_on_board(*pieces_properties[1]->piece_name(), 1, 1);
  put_piece_on_board(*pieces_properties[1]->piece_name(), 1, 6);
  // 0 Knight
  put_piece_on_board(*pieces_properties[1]->piece_name(), 1,
                    (7 * default_size) + 1);
  put_piece_on_board(*pieces_properties[1]->piece_name(), 1,
                     (7 * default_size) + 6);
  // 1 Bishop
  put_piece_on_board(*pieces_properties[2]->piece_name(), 1, 2);
  put_piece_on_board(*pieces_properties[2]->piece_name(), 1, 5);
  // 0 Bishop
  put_piece_on_board(*pieces_properties[2]->piece_name(), 0,
                     (7 * default_size) + 2);
  put_piece_on_board(*pieces_properties[2]->piece_name(), 0,
                     (7 * default_size) + 5);
  // 1 Queen
  put_piece_on_board(*pieces_properties[4]->piece_name(), 1, 3);
  put_piece_on_board(*pieces_properties[4]->piece_name(), 0,
                     (7 * default_size) + 3);
  // 1 King
  put_piece_on_board(*pieces_properties[5]->piece_name(), 1, 4);
  put_piece_on_board(*pieces_properties[5]->piece_name(), 0,
                     (7 * default_size) + 4);
}

Board::Board(unsigned int board_size,
           const std::vector<std::shared_ptr<Piece>> pieces_properties,
           const std::vector<Player> player_list)
    : board(new board_cell[board_size * board_size]),
      side_length(board_size),
      pieces_properties(pieces_properties) {}

Board::~Board() {
  this->pieces_properties.clear();
  this->pieces_properties.shrink_to_fit();
  delete[] this->board;
}

bool Board::check_free_position(std::vector<struct position> position_list) {
  unsigned int index_board;
  struct board_cell *cell_to_check;

  for (struct position &p : position_list) {
    index_board = position_in_board(p);
    cell_to_check = &this->board[index_board];
    if (!cell_to_check->piece_type.empty()) {
      return false;
    }
  }
  return true;
}

void Board::try_move_piece(position &start_position, position &end_position) {
  const unsigned int start_index_in_board = position_in_board(start_position);
  const unsigned int end_index_in_board = position_in_board(end_position);
  board_cell &start_cell = board[start_index_in_board];
  board_cell &end_cell = board[end_index_in_board];
  std::shared_ptr<Piece> start_piece;
  std::shared_ptr<Piece> end_piece;
  std::vector<struct position> position_to_be_free;

  // todo : refactor this shit please
  start_piece = find_piece_type(start_cell.piece_type);
  if (start_piece) {
    end_piece = find_piece_type(end_cell.piece_type);
    if (end_piece) {
      position_to_be_free = *start_piece->context_to_check_normal_move(
          start_position, end_position);

      if (start_cell.player != end_cell.player &&
          start_piece->attack_move_no_context(start_position, end_position) &&
          check_free_position(position_to_be_free)) {
        move_piece_in_board(start_cell, end_cell);
      }
    } else if (start_piece->normal_move_no_context(start_position,
                                                   end_position)) {
      position_to_be_free = *start_piece->context_to_check_normal_move(
          start_position, end_position);
      if (check_free_position(position_to_be_free)) {
        move_piece_in_board(start_cell, end_cell);
      }
    }
  }
  position_to_be_free.clear();
  position_to_be_free.shrink_to_fit();
}

void Board::print_board() const {
  unsigned int index_board;
  for (int i = 0; i < this->side_length; i++) {
    for (int j = 0; j < this->side_length; j++) {
      index_board = (i * this->side_length) + j;
      if (this->board[index_board].player == 1) {
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
void Board::move_piece_in_board(struct board_cell &start,
                               struct board_cell &end) {
  end.piece_type = start.piece_type;
  end.player = start.player;
  start.piece_type.clear();
  start.never_moved = false;
  end.never_moved = false;
}
void Board::put_piece_on_board(const std::string piece_name,
                              const unsigned int player,
                              const unsigned int pos) const {
  this->board[pos].piece_type = piece_name;
  this->board[pos].player = player;
}

std::shared_ptr<Piece> Board::find_piece_type(const std::string &type) {
  if (type.empty()) {
    return nullptr;
  }
  for (std::shared_ptr<Piece> p : this->pieces_properties) {
    if (*p->piece_name() == type) {
      return p;
    }
  }
  return nullptr;
}
unsigned int Board::position_in_board(position &start_position) const {
  unsigned int first_dimension = start_position.y * this->side_length;
  unsigned int second_dimension = start_position.x;
  return first_dimension + second_dimension;
}


