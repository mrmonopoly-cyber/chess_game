#ifndef _GENERIC_PIECE_
#define _GENERIC_PIECE_

#include <iostream>
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
  std::string *piece_name() const;
  virtual bool normal_move_no_context(const position &start_position,
                                      const position &end_position);
  // {
  //   std::cout << "default operation " << std::endl;
  //   return false;
  // }
  virtual bool attack_move_no_context(const position &start_position,
                                      const position &end_position);
  // {
  //   std::cout << "default operation " << std::endl;
  //   return false;
  // }
  virtual bool special_move_no_context(const position &start_position,
                                       const position &end_position);
  // {
  //   std::cout << "default operation " << std::endl;
  //   return false;
  // }

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
                              const position &end_position);
  bool attack_move_no_context(const position &start_position,
                              const position &end_position);
  bool special_move_no_context(position const &start_position,
                               position const &end_position);
};
class Knight : public Piece {
 public:
  Knight();
  ~Knight();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position);
  bool attack_move_no_context(const position &start_position,
                              const position &end_position);

 private:
  bool l_movement(const position &start_position,
                  const position &end_position) const;
};

class Bishop : public Piece {
 public:
  Bishop();
  ~Bishop();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position);
  bool attack_move_no_context(const position &start_position,
                              const position &end_position);
};

class Rook : public Piece {
 public:
  Rook();
  ~Rook();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position);
  bool attack_move_no_context(const position &start_position,
                              const position &end_position);
};

class Queen : public Piece {
 public:
  Queen();
  ~Queen();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position);
  bool attack_move_no_context(const position &start_position,
                              const position &end_position);
};

class King : public Piece {
 public:
  King();
  ~King();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position);
  bool attack_move_no_context(const position &start_position,
                              const position &end_position);
  bool special_move_no_context(position const &start_position,
                               position const &end_position);
};

}  // namespace backand

#endif  // !_GENERIC_PIECE_
