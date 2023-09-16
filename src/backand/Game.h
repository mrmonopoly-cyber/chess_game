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

};


int main(int argc, char *argv[]) {
    Game game;
    // board is divided in coloms
    struct position moves[] = {{0, 1}, {0, 2},{0,2},{1,3}, {0, 3}, {1, 3}};
    game.move_piece(moves[0], moves[1]);
    game.move_piece(moves[2], moves[3]);
    game.move_piece(moves[4], moves[5]);
    game.game_status();
    return 0;
}
