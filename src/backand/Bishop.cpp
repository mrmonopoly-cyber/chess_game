#include "Piece.h"

class Bishop : protected Piece {
 protected:
  Bishop() : Piece(BISHOP){};

  ~Bishop();

  bool is_a_valid_move_no_context(struct position *start_position,
                                  position *end_position) {
    return true;
  };
};
