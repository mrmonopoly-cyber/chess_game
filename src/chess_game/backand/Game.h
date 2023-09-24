#pragma once
/*
 * Author : Alberto Damo
 * Date : 2023-09-21
 *
 * Implementation of chess board game using the  in current project
 */
#include <array>
#include <cstddef>
#include <functional>
#include "include/framework/Board.h"
#include "include/chess_game/backand/Chess_pieces.h"

#define SIDE_V 8
#define SIDE_H 8
#define N_PIECE_TYPES 6
#define N_PLAYERS 2
#define N_INITIAL_PIECES 32

using namespace framework;

namespace chess {
    class Chess_board : public Board<SIDE_H, SIDE_V, N_PIECE_TYPES, N_PLAYERS, N_INITIAL_PIECES>
    {
        public:
            Chess_board();
            bool board_peculiar_status_maintained(const unsigned int player) const override;
        private:
            bool find_enemy_piece(position &start_position, const int increment_x,
                    const int increment_y, const unsigned int owner)const;
            bool is_enemy_knight(position pos, const unsigned int player) const;


            mutable std::array<bool,2> kings_check = {false,false};
    };

    class Chess_game
    {
        public:
            /*
             * CONSTRUCTOR : create a new chess game
             */
            Chess_game();
            ~Chess_game();
            /*
             * METHOD: restart the existing game without reallocating all the memory
             */
            void restart_game();
            /*
             * METHOD: try to move a piece in the board, if the move is valid and the turn is 
             * correct the move will be applied and the turn will change to the next player.
             * Else nothing happen, the state of the game will not change
             */
            void move_piece(position &start,position &end);
            /*
             * METHOD: print in std output the current status of the board and the player who has 
             * to play
             */
           void game_status() const;
        private:
            Chess_board board;
            unsigned char current_player_turn = 0;
    };
}
