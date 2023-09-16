#ifndef _PIECES_
#define _PIECES_
#include <iostream>
#include <memory>
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
  virtual std::vector<struct position> *context_to_check_normal_move(
      position &start_position, position &end_position);
  virtual std::vector<struct position> *context_to_check_special_move(
          const position &start_position,const position &end_position);
  virtual bool normal_move_no_context(const position &start_position,
                                      const position &end_position);
  virtual bool attack_move_no_context(const position &start_position,
                                      const position &end_position);
  virtual bool special_move_no_context(const position &start_position,
                                       const position &end_position,
                                       const std::vector<struct position> context);

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

  std::vector<struct position> *context_to_check_normal_move(
      position &start_position, position &end_position) override;
  std::vector<struct position> *context_to_check_special_move(
          const position &start_position,const position &end_position)override;

  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position,
                               const std::vector<struct position> context) override;
};
class Knight : public Piece {
 public:
  Knight();
  ~Knight();
  std::vector<struct position> *context_to_check_normal_move(
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
  std::vector<struct position> *context_to_check_normal_move(
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
  std::vector<struct position> *context_to_check_normal_move(
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
  std::vector<struct position> *context_to_check_normal_move(
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
  std::vector<struct position> *context_to_check_normal_move(
      position &start_position, position &end_position) override;
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position,
                               const std::vector<struct position> context) override;
};

}  // namespace backand
#endif //!_PIECES_
