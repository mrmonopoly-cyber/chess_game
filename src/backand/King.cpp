#include <cstdlib>

#include "Piece.h"

class King : protected Piece {
 protected:
  King() : Piece(KING){};

  ~King();

  bool is_a_valid_move_no_context(struct position *start_position,
                                  position *end_position) {
    unsigned int diff_x = abs(start_position->x - end_position->x);
    unsigned int diff_y = abs(start_position->y - end_position->y);

    if (diff_x <= 1 && diff_y <= 1) {  // normal move case
      return true;
    }

    if (diff_y == 0 && diff_x == 2) {  // castle case
      return true;
    }
    return false;
  };
};
