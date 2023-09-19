#ifndef _BOARD_GENERAL_
#define _BOARD_GENERAL_
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>

#include "include/framework/Player.h"
#include "include/framework/Piece.h"
#include "include/framework/Board_cell.h"

namespace framework {
    template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER, unsigned int N_DEF_PIECE>
        class Board {
            public:
                Board() = delete;
                Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER,N_DEF_PIECE>(const std::array<const Piece,PIECE_TYPES> &pieces_properties,
                        const std::array<const Player,N_PLAYER> &player_list,
                        const std::array<const cell_configuration,N_DEF_PIECE> & default_board_configuration)
                    :pieces_properties(pieces_properties),players(player_list),
                    default_board_configuration(default_board_configuration)
                {
                    apply_default_conf_board();
                }

                Board<SIDE_H,SIDE_V,PIECE_TYPES,N_PLAYER,N_DEF_PIECE>(const std::array<const Piece,PIECE_TYPES> &pieces_properties,
                        const std::array<const Player,N_PLAYER> &player_list,
                        const std::array<const cell_configuration,N_DEF_PIECE> & default_board_configuration,
                        const std::function<bool(void)>board_peculiar_status_mantained)
                :pieces_properties(pieces_properties),players(player_list),
                    default_board_configuration(default_board_configuration),
                    board_peculiar_status_mantained(board_peculiar_status_mantained)
                {
                    apply_default_conf_board();
                }

                ~Board()
                {
                    //ok to be empty
                }

                void reset_board()
                {
                    for(struct Board_cell &b : this->board)
                    {
                        b.reset();
                    }
                    apply_default_conf_board();
                }
                void put_piece(const Piece &piece, const position pos,const Player &player)
                {
                    framework::Board_cell &cell = find_cell(pos);
                    int p_index = find_player(player);
                    if(p_index == -1){
                        return;
                    }
                    cell.overwrite(*piece.piece_name(), p_index);
                }
                void try_move_piece(position &start_position, position &end_position,
                        const unsigned int player)
                {
                    Board_cell *start_cell;
                    Board_cell *dest_cell;
                    Piece *start_piece;
                    std::vector<struct position> *context_to_check;
                    unsigned int vector_size;

                    //cells
                    start_cell = find_cell(start_position);
                    if(!start_cell){
                        return;
                    }
                    dest_cell = find_cell(end_position);
                    if(!dest_cell)
                    {
                        return;
                    }

                    //piece
                    start_piece = find_piece_category(start_cell->get_type());
                    if(!start_piece){
                        return;
                    }

                    //position to check   
                    context_to_check = start_piece->context_to_check(start_position,end_position,start_cell->get_owner());
                    vector_size = context_to_check->size();

                    //cells to check
                    const struct framework::Board_cell cell_to_check[vector_size];
                    for(int i =0; i < vector_size;i++)
                    {
                        cell_to_check[i] = find_cell(context_to_check[i]);
                    }

                    //checking fase
                    if(start_piece->valid_move(cell_to_check,context_to_check,vector_size) && board_peculiar_status_mantained())
                    {
                        //moving piece
                        dest_cell->overwrite(*start_cell);
                        dest_cell->reset();
                    }

                    //free the memory
                    context_to_check->clear();
                    context_to_check->shrink_to_fit();
                    delete context_to_check;
                }
                void print_board() const
                {
                    unsigned int cursor = 0;
                    for(const Board_cell & cell : board){
                        std::cout << cell << " ";
                        cursor++;
                        if(cursor == SIDE_H){
                            std::cout << std::endl;
                            cursor =0;
                        }
                    }
                }
                const unsigned int board_area()const{
                    return SIDE_V * SIDE_H;
                }
            private:
                void apply_default_conf_board()
                {
                    Board_cell * cell;
                    const Piece *piece;
                    for(const cell_configuration &c : default_board_configuration)
                    {
                        cell = find_cell({c.x,c.y});
                        piece = &this->pieces_properties[c.Piece_index];
                        if(!cell){
                            continue;
                        }
                        cell->overwrite(*(piece->piece_name()),c.Piece_owner);
                        cell = nullptr;
                    }
                }
                int find_player(const Player &player) const
                {
                    for(int i=0;i<players.size();i++){
                        if(players[i].player_name() == player.player_name()){
                            return i;
                        }
                    }
                    return -1;
                }
                Board_cell *find_cell(const struct position &pos)
                {
                    const unsigned int index = pos.x + (pos.y * SIDE_V);   
                    if(index >= 0 && index < (SIDE_H * SIDE_V))
                    {
                        return nullptr;
                    }

                    return &board[index];
                }
                const Piece *find_piece_category(const std::string &piece_type)
                {
                    if(piece_type.empty()){
                        return nullptr;
                    }
                    for(const Piece *p : pieces_properties)
                    {
                        if(*(*p).piece_name() == piece_type){
                            return p;
                        }
                    }
                    return nullptr;
                }
                Piece *get_piece(const position *pos)const;

                const std::array<const Piece,PIECE_TYPES> pieces_properties;
                std::array<Board_cell,SIDE_H*SIDE_V> board;
                const std::array<const Player,N_PLAYER> players;
                const std::array<const cell_configuration,N_DEF_PIECE> & default_board_configuration;
                const std::function<bool(void)>board_peculiar_status_mantained = [](){return true;};
        };
}  // namespace framework
#endif //!_BOARD_GENERAL_
