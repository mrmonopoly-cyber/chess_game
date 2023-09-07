#pragma one
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

class Pawn : public Piece {
 public:
  Pawn();
  bool special_move_no_context(position &start_position,
                               position &end_position);
};

class Knight : public Piece {
 public:
  Knight();
};

class Bishop : public Piece {
 public:
  Bishop();
};

class Rook : public Piece {
 public:
  Rook();
};

class Queen : public Piece {
 public:
  Queen();
};

class King : public Piece {
 public:
  King();
  bool special_move_no_context(position &start_position,
                               position &end_position);
};

}  // namespace backand
