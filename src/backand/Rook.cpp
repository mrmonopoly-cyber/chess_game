#include "Piece.h"

class Rook : protected Piece {
 protected:
  Rook() : Piece(ROOK){};

  ~Rook();

  bool is_a_valid_move_no_context(struct position *start_position,
                                  position *end_position) {
    return true;
  };
};
