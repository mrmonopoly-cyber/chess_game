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
                            const std::array<Player,N_PLAYER> player_list,
                            const std::function<void(void)>default_board_configuration);
                    Board(const std::array<Piece,PIECE_TYPES> pieces_properties,
                            const std::array<Player,N_PLAYER> player_list,
                            const std::function<void(void)>default_board_configuration,
                            const std::function<bool(void)>board_peculiar_status_mantained);

                    ~Board();
                    void reset_board();
                    void try_move_piece(position &start_position, position &end_position,
                            const unsigned int player);
                    void print_board() const;
                    const unsigned int board_area(){
                        return SIDE_V * SIDE_H;
                    }
                private:
                    Board_cell *find_cell(const struct position &pos)const;
                    const Piece *find_piece_category(const std::string &piece_type);
                    Piece *get_piece(const position *pos)const;

                    const std::array<const Piece,PIECE_TYPES> pieces_properties;
                    const std::array<Board_cell,SIDE_H*SIDE_V> board;
                    const std::array<const Player,N_PLAYER> players;
                    const std::function<void(void)>default_board_configuration;
                    const std::function<bool(void)>board_peculiar_status_mantained;
            };
}  // namespace framework
#endif //!_BOARD_GENERAL_
