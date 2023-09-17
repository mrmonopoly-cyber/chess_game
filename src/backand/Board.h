#pragma one
#include <memory>
#include <string>
#include <vector>
#include <array>

#include "Player.h"
#include "Piece.h"
#include "Board_cell.h"


namespace backand {
    template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
        unsigned int N_PLAYER>
        class Board {
            public:
                Board() = delete;
                Board(const std::array<Piece,PIECE_TYPES> pieces_properties,
                        const std::vector<Player> player_list);
                ~Board();
                bool try_move_piece(position &start_position, position &end_position,
                        const unsigned int player);
                void print_board() const;
                const unsigned int board_area(){
                    return SIDE_V * SIDE_H;
                }
            private:
                const std::array<Piece,PIECE_TYPES> pieces_properties;
                const std::array<struct board_cell,SIDE_H*SIDE_V> board;
                const std::array<Player,N_PLAYER> players;
        };
}  // namespace backand
