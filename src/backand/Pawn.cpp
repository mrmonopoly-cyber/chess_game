#include "Piece.h"

class Pawn : protected Piece {
 protected:
  Pawn() : Piece(PAWN){};

  ~Pawn(){};

  bool is_a_valid_move_no_context(struct position *start_position,
                                  position *end_position) {
    return true;
  };
};
