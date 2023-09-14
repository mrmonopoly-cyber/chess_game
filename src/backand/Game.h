#ifndef _BOARD_GAME_
#define _BOARD_GAME_

#include <memory>
#include <string>
#include <vector>

#include "Piece.h"

namespace backand {

class Game {
 public:
  Game();
  Game(const unsigned int board_size,
       const std::vector<std::shared_ptr<Piece>> pieces_properties);
  ~Game();
  void try_move_piece(position &start_position, position &end_position);
  void print_board() const;

 private:
  struct board_cell {
    std::string piece_type;
    Piece::PIECE_COLOR color;
  };
  static const unsigned int default_size = 8;

  std::vector<std::shared_ptr<Piece>> pieces_properties;
  const unsigned int side_length;
  struct board_cell *const board;
  // Game_log moves_history;

  bool check_free_position(std::vector<struct position> position_list);
  void move_piece_in_board(struct board_cell &start, struct board_cell &end);
  void put_piece_on_board(const std::string piece_name,
                          const Piece::PIECE_COLOR color,
                          const unsigned int pos) const;
  unsigned int position_in_board(position &start_position) const;
  std::shared_ptr<Piece> find_piece_type(const std::string &type);
};
}  // namespace backand
#endif  // !_BOARD_GAME_
