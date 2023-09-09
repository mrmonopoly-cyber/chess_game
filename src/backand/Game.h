#ifndef _BOARD_GAME_
#define _BOARD_GAME_

#include <vector>

#include "Piece.h"

namespace backand {

class Game {
 protected:
  Game();
  Game(const unsigned int board_size,
       const std::vector<Piece> pieces_properties);
  ~Game();
  void try_move_piece(position &start_position, position &end_position);

 private:
  struct board_cell {
    char *piece_type;
    Piece::PIECE_COLOR color;
  };
  static const unsigned int default_size = 8;

  std::vector<Piece> pieces_properties;
  const unsigned int side_length;
  const board_cell *board;
  // Game_log moves_history;

  unsigned int position_in_board(position &start_position);
};

}  // namespace backand
#endif  // !_BOARD_GAME_
