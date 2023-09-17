#ifndef _BOARD_GENERAL_
#define _BOARD_GENERAL_
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>

#include "Player.h"
#include "Piece.h"
#include "Board_cell.h"


namespace framework {
    template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
        unsigned int N_PLAYER>
        class Board {
            public:
                Board() = delete;
                Board(const std::array<Piece,PIECE_TYPES> pieces_properties,
                        const std::vector<Player> player_list,
                        const std::function<void(void)>default_board_configuration);
                ~Board();
                void reset_board();
                virtual bool try_move_piece(position &start_position, position &end_position,
                        const unsigned int player) =0;
                void print_board() const;
               const unsigned int board_area(){
                    return SIDE_V * SIDE_H;
                }
            private:
                const std::array<Piece,PIECE_TYPES> pieces_properties;
                const std::array<struct board_cell,SIDE_H*SIDE_V> board;
                const std::array<Player,N_PLAYER> players;
                std::function<void(void)>default_board_configuration;
        };
}  // namespace framework
#endif //!_BOARD_GENERAL_
