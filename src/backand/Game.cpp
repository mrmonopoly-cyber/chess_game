#include "Game.h"

Game::Game(){
}

void Game::game_status()const{
    this->game_board.print_board();
}

void Game::move_piece(position &start_position, position &end_position){
    game_board.try_move_piece(start_position, end_position);
}
