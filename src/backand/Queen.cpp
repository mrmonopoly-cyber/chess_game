#include "Piece.h"

class Queen : protected Piece {
 protected:
  Queen() : Piece(QUEEN){};

  ~Queen();

  bool is_a_valid_move_no_context(struct position *start_position,
                                  position *end_position) {
    unsigned int diff_x = start_position->x - end_position->x;
    unsigned int diff_y = start_position->y - end_position->y;

    if (diff_x == 0 || diff_y == 0) {
      return true;
    }

    if (diff_y == diff_x) {
      return true;
    }

    return true;
  };
};
