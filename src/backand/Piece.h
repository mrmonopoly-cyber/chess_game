#pragma one
namespace backand {

struct position {
  int x;
  int y;
};

class Piece {
 public:
  enum PIECE_COLOR { BLACK = 0, WHITE };

  Piece();
  Piece(const int range);
  ~Piece();
  virtual bool normal_move_no_context(const position &start_position,
                                      const position &end_position) const = 0;
  virtual bool attack_move_no_context(const position &start_position,
                                      const position &end_position) const = 0;
  virtual bool special_move_no_context(const position &start_position,
                                       const position &end_position) const = 0;

 protected:
  bool vertical_check(const position &start_position,
                      const position &end_position) const;
  bool horizontal_check(const position &start_position,
                        const position &end_position) const;
  bool diagonal_check(const position &start_position,
                      const position &end_position) const;

 protected:
  unsigned int range;
};

class Pawn : public Piece {
 public:
  Pawn();
  ~Pawn();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const override;
};

class Knight : public Piece {
 public:
  Knight();
  ~Knight();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const override;

 private:
  bool l_movement(const position &start_position,
                  const position &end_position) const;
};

class Bishop : public Piece {
 public:
  Bishop();
  ~Bishop();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const override;
};

class Rook : public Piece {
 public:
  Rook();
  ~Rook();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const override;
};

class Queen : public Piece {
 public:
  Queen();
  ~Queen();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const override;
};

class King : public Piece {
 public:
  King();
  ~King();
  bool normal_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool attack_move_no_context(const position &start_position,
                              const position &end_position) const override;
  bool special_move_no_context(position const &start_position,
                               position const &end_position) const override;
};

}  // namespace backand
