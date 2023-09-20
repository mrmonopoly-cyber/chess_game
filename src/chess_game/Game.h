#ifndef _CHESS_GAME_
#define _CHESS_GAME_

#include <cstddef>
#include "include/framework/Board.h"
#include "include/framework/Player.h"
#include "include/chess_game/Chess_pieces.h"

namespace chess {
    class Chess_game
    {
        public:
            Chess_game();
            ~Chess_game();
            void restart_game();
            void move_piece(framework::position &start,framework::position &end);
           void game_status() const;
        private:
            framework::Board<8, 8, 6, 2, 32> board ;
            unsigned int current_player_turn = 0;
    };
}

#endif //!_CHESS_GAME_
