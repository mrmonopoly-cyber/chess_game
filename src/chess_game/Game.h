#pragma once
/*
 * Author : Alberto Damo
 * Date : 2023-09-21
 *
 * Implementation of chess board game using the framework in current project
 */
#include <cstddef>
#include "include/framework/Board.h"
#include "include/chess_game/Chess_pieces.h"

#define SIDE_V 8
#define SIDE_H 8
#define N_PIECES_TYPES 6
#define N_PLAYERS 2
#define N_INITIAL_PIECES 32

namespace chess {
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
            void move_piece(framework::position &start,framework::position &end);
            /*
             * METHOD: print in std output the current status of the board and the player who has 
             * to play
             */
           void game_status() const;
        private:
            framework::Board<SIDE_V, SIDE_H, N_PIECES_TYPES, N_PLAYERS, N_INITIAL_PIECES> board;
            unsigned char current_player_turn = 0;
    };
}
