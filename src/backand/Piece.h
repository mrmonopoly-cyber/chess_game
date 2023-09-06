#ifndef _GENERIC_PIECE_
#define _GENERIC_PIECE_

#include <vector>
class Piece {
 protected:
  enum PIECE_TYPE {
    NULL_PIECE = 0,
    PAWN = (1 << 0),
    KNIGHT = (1 << 1),
    BISHOP = (1 << 2),
    ROOK = (1 << 3),
    QUEEN = (1 << 4),
    KING = (1 << 5)
  };

  struct position {
    int x;
    int y;
  };

 private:
  PIECE_TYPE type;

 protected:
  Piece(PIECE_TYPE type);
  bool is_a_valid_move_no_context(position *start_position,
                                  position *end_position);
  ~Piece();
};

#endif  // !_GENERIC_PIECE_
