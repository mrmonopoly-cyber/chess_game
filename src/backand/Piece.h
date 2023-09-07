#ifndef _ALL_PIECES_
#define _ALL_PIECES_

namespace backand {

struct position {
  int x;
  int y;
};

enum PIECE_TYPE { NULL_PIECE = 0, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum PIECE_COLOR { BLACK, WHITE };

class Piece {
 public:
  Piece();
  Piece(const PIECE_TYPE type, const unsigned int movement,
        const unsigned int attack, const int range);
  ~Piece();
  Piece &operator=(Piece &&other) noexcept;
  bool normal_move_no_context(position &start_position, position &end_position);
  bool attack_move_no_context(position &start_position, position &end_position);
  bool special_move_no_context(position &start_position,
                               position &end_position);

 protected:
  enum piece_movement {
    VERTICAL = (1 << 0),
    HORIZONTAL = (1 << 1),
    DIAGONAL = (1 << 2),
    L_MOVE = (1 << 3),
    ONLY_UP = (1 << 4)
  };

 private:
  PIECE_TYPE type;
  unsigned int valid_movement;
  unsigned int valid_attack;
  unsigned int range;

  bool valid_move(unsigned int movement, unsigned int range,
                  position &start_position, position &end_position);
};

class Pawn : protected Piece {
  Pawn();
  Pawn &operator=(Pawn &&other) noexcept;
  bool special_move_no_context(position &start_position,
                               position &end_position);
};

class Knight : protected Piece {
  Knight();
};

class Bishop : protected Piece {
  Bishop();
};

class Rook : protected Piece {
  Rook();
};

class Queen : protected Piece {
  Queen();
};

class King : protected Piece {
  King();
  bool special_move_no_context(position &start_position,
                               position &end_position);
};

}  // namespace backand
#endif  // !_ALL_PIECES_
