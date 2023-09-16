#pragma one
#include <memory>
#include <string>
#include <vector>

#include "Player.h"
#include "Piece.h"


namespace backand {

class Board {
 public:
  Board();
  Board(const unsigned int board_size,
       const std::vector<std::shared_ptr<Piece>> pieces_properties,
       const std::vector<Player> player_list);
  ~Board();
  void try_move_piece(position &start_position, position &end_position);
  void print_board() const;

 private:
  struct board_cell {
    std::string piece_type;
    unsigned int player;
    bool never_moved = true;
  };
  static const unsigned int default_size = 8;

  std::vector<std::shared_ptr<Piece>> pieces_properties;
  const unsigned int side_length;
  struct board_cell *const board;

  bool check_free_position(std::vector<struct position> position_list);
  void move_piece_in_board(struct board_cell &start, struct board_cell &end);
  void put_piece_on_board(const std::string piece_name,
                          const unsigned int color,
                          const unsigned int pos) const;
  unsigned int position_in_board(position &start_position) const;
  std::shared_ptr<Piece> find_piece_type(const std::string &type);
};
}  // namespace backand
