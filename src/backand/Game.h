#ifndef _BOARD_GAME_
#define _BOARD_GAME_

#include <vector>

#include "Piece.h"

namespace backand {

class Game {
 protected:
  Game();
  Game(unsigned int board_size, std::vector<Piece> pieces_properties);
  ~Game();
  void try_move_piece(position &start_position, position &end_position);

 private:
  struct board_cell {
    char *piece_type;
    Piece::PIECE_COLOR color;
  };
  std::vector<Piece> pieces_properties;
  const board_cell *board;
  // Game_log moves_history;

  unsigned int position_in_board(position &start_position);
};

}  // namespace backand
#endif  // !_BOARD_GAME_
