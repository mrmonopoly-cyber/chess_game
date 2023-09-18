#ifndef _CHESS_GAME_
#define _CHESS_GAME_

#include <cstddef>
#include "include/framework/Board.h"
#include "include/framework/Player.h"
#include "Chess_pieces.h"

namespace chess {
    class Chess_game
    {
        public:
            Chess_game();
            ~Chess_game();
            void restart_game();
            void game_status() const;
        private:
            framework::Board<8, 8, 6, 2> board ;
    };
}

#endif //!_CHESS_GAME_
