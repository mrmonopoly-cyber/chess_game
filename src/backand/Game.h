#ifndef _GAME_
#define _GAME_

#include <cmath>
#include <vector>

#include "Piece.h"

namespace backand {

class Game {
 protected:
  Game();
  Game(unsigned int board_size);
  ~Game();
  void try_move_piece(position &start_position, position &end_position);

 private:
  struct piece_in_board {
    PIECE_TYPE type;
    PIECE_COLOR color;
  };

  unsigned int board_size;
  std::vector<Piece *> Pieces_properties;
  piece_in_board *board;
  // Game_log moves_history;

  unsigned int position_in_board(position &start_position);
};

}  // namespace backand
#endif  // !_GAME_
