#ifndef _BOARD_GAME_
#define _BOARD_GAME_

#include <string>
#include <vector>

#include "Piece.h"

namespace backand {

class Game {
 public:
  Game();
  Game(const unsigned int board_size,
       const std::vector<Piece> pieces_properties);
  ~Game();
  void try_move_piece(position &start_position, position &end_position) const;
  void print_board() const;

 private:
  struct board_cell {
    std::string piece_type;
    Piece::PIECE_COLOR color;
  };
  static const unsigned int default_size = 8;

  std::vector<Piece> pieces_properties;
  const unsigned int side_length;
  struct board_cell *board;
  // Game_log moves_history;

  void put_piece_on_board(const std::string piece_name,
                          const Piece::PIECE_COLOR color,
                          const unsigned int pos);
  unsigned int position_in_board(position &start_position) const;
  bool valid_move_no_context(position &start_position,
                             position &end_position) const;
};

}  // namespace backand
#endif  // !_BOARD_GAME_
