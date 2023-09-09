#ifndef _GENERIC_PIECE_
#define _GENERIC_PIECE_

#include <string>
namespace backand {

struct position {
  int x;
  int y;
};

class Piece {
 public:
  enum PIECE_COLOR { BLACK = 0, WHITE };

  Piece() = delete;
  Piece(const char *const name);
  Piece(const int range, const char *const name);
  ~Piece();
  virtual bool normal_move_no_context(const position &start_position,
                                      const position &end_position);
  virtual bool attack_move_no_context(const position &start_position,
                                      const position &end_position);
  virtual bool special_move_no_context(const position &start_position,
                                       const position &end_position);

 protected:
  bool vertical_check(const position &start_position,
                      const position &end_position) const;
  bool horizontal_check(const position &start_position,
                        const position &end_position) const;
  bool diagonal_check(const position &start_position,
                      const position &end_position) const;

 protected:
  unsigned int range;
  const std::string name;
};

class Pawn : public Piece {
 public:
  Pawn();
  ~Pawn();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const;
};

class Knight : public Piece {
 public:
  Knight();
  ~Knight();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const;

 private:
  bool l_movement(const position &start_position,
                  const position &end_position) const;
};

class Bishop : public Piece {
 public:
  Bishop();
  ~Bishop();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const;
};

class Rook : public Piece {
 public:
  Rook();
  ~Rook();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const;
};

class Queen : public Piece {
 public:
  Queen();
  ~Queen();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const;
};

class King : public Piece {
 public:
  King();
  ~King();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const;
};

}  // namespace backand

#endif  // !_GENERIC_PIECE_
