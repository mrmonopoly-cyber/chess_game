#ifndef _GENERIC_PIECE_
#define _GENERIC_PIECE_

struct position {
  int x;
  int y;
};

class Piece {
 private:
  unsigned int type;
  unsigned int valid_movement;
  unsigned int range;

 protected:
  Piece(unsigned int type, unsigned int movement, int range);
  virtual bool normal_move_no_context(position &start_position,
                                      position &end_position) = 0;
  virtual bool attack_move_no_context(position &start_position,
                                      position &end_position) = 0;
  virtual bool special_move_no_context(position &start_position,
                                       position &end_position) = 0;
  virtual ~Piece();
};

#endif  // !_GENERIC_PIECE_
