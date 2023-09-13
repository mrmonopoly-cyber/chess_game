#ifndef _GENERIC_PIECE_
#define _GENERIC_PIECE_

#include <iostream>
#include <string>
#include <vector>
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
  Piece(const int range, const char *const name, bool jump_pieces);
  ~Piece();
  std::string *piece_name() const;
  virtual const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) = 0;
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
  unsigned int range = 0;
  const std::string name;
  bool jump_pieces = false;
};

class Pawn : public Piece {
 public:
  Pawn();
  ~Pawn();
  const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) override;
};
class Knight : public Piece {
 public:
  Knight();
  ~Knight();
  const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;

 private:
  bool l_movement(const position &start_position,
                  const position &end_position) const;
};

class Bishop : public Piece {
 public:
  Bishop();
  ~Bishop();
  const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
};

class Rook : public Piece {
 public:
  Rook();
  ~Rook();
  const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
};

class Queen : public Piece {
 public:
  Queen();
  ~Queen();
  const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
};

class King : public Piece {
 public:
  King();
  ~King();
  const std::vector<struct position> context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) override;
};

}  // namespace backand

#endif  // !_GENERIC_PIECE_
