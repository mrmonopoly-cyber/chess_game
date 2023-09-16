#include "Game.h"
#include <vector>

Game::Game(): players(std::vector<Player>(0)),current_player_turn(0){
   this->players.emplace_back(Player("White"));
   this->players.emplace_back(Player("Black"));
}

void Game::game_status()const{
    this->game_board.print_board();
}

void Game::move_piece(position &start_position, position &end_position){
    if(!game_board.try_move_piece(start_position, end_position,this->current_player_turn)){
        return;
    }
    this->current_player_turn++;
    if (this->current_player_turn < this->players.size()) {
        return;
    }
    this->current_player_turn=0;

}
