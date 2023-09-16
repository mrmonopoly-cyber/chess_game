#pragma one
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Piece.h"

using namespace backand;

class Game{
    public:
        Game();
        void move_piece(struct position &start_position, struct position &end_position) ;
        void game_status() const;
    private:
        std::vector<Player> players;
        backand::Board game_board;
        unsigned int current_player_turn;

};
