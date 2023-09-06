#include "Piece.h"

class Knight : protected Piece {
 protected:
  Knight() : Piece(KNIGHT){};

  ~Knight();

  bool is_a_valid_move_no_context(struct position *start_position,
                                  position *end_position) {
    return true;
  };
};
