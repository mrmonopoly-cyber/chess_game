#ifndef _GENERIC_PIECE_
#define _GENERIC_PIECE_

namespace backand {

struct position {
  int x;
  int y;
};

enum PIECE_TYPE { NULL_PIECE = 0, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum PIECE_COLOR { BLACK, WHITE };

class Piece {
 protected:
  Piece(PIECE_TYPE type, unsigned int movement, unsigned int attack, int range);
  bool normal_move_no_context(position &start_position, position &end_position);
  bool attack_move_no_context(position &start_position, position &end_position);
  virtual bool special_move_no_context(position &start_position,
                                       position &end_position) = 0;
  virtual ~Piece();

 private:
  PIECE_TYPE type;
  unsigned int valid_movement;
  unsigned int valid_attack;
  unsigned int range;
};

}  // namespace backand
#endif  // !_GENERIC_PIECE_
