#include <cmath>
#include <list>
#include <vector>

#include "Piece.h"

namespace backand {

class GAME {
 protected:
  GAME();
  ~GAME();
  void try_move_piece(position &start_position, position &end_position);

 private:
  class Game_log {
   private:
    struct move {
      PIECE_TYPE type;
      position &start_position;
      position &end_position;
    };
    std::list<struct move> move_list;

   protected:
    move get_move_at_index(unsigned int index);
    void insert_move(PIECE_TYPE piece, position &start_position,
                     position &end_position);
    void print_log();
    Game_log();
    ~Game_log();
  };

  struct piece_in_board {
    PIECE_TYPE type;
    PIECE_COLOR color;
  };

  std::vector<Piece> Pieces_properties;
  std::vector<piece_in_board> board;
  Game_log moves_history;
};

}  // namespace backand
