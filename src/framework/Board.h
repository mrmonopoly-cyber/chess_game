#pragma once
/*
 * author : Alberto Damo
 * date : 2023-09-20
 * Class : Board.h
 *
 * This Template Class enable the user to create infinite amount of Board Games (chess, dama, etc)
 * The board is a rectangular type and the dimension of the board is defined by the parameters:
 *  1- SIDE_V : size of vertical side
 *  2- SIDE_H : size of horizontal side
 * The parameters have the next meaning: 
 *  3- PIECE_TYPES : number of different type of pieces in the game
 *  4- N_PLAYER : number of player per match
 *  5- N_DEF_PIECE : number of pieces in the initial board configuration
 * If you want to create a board game you simply need to use one of the constructor (The default 
 * empty constructor is disable) where you can specify the different pieces, the players, 
 * the default configuration and, if you need, a function to check peculiar status of the board
 * (like king check in chess).
 *
 * The valid moves are built in the Pieces itself, this board class will only interrogate them to 
 * understand if a move is valid or not. (Piece.h). 
 */
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>

#include "Board_cell.h"
#include "include/framework/Piece.h"
#include "include/framework/Board_cell.h"
#include "include/framework/Board_move_log.h"

using std::array;
using std::function;
using std::vector;

namespace framework {
    template<unsigned int SIDE_H,unsigned int SIDE_V,unsigned int PIECE_TYPES, 
    unsigned int N_PLAYER, unsigned int N_DEF_PIECE>
        class Board {
            public:
                Board() = delete;
                /*CONSTRUCTOR: it will create a board with no peculiar status to check
                 * @ piece_properties : Array of all the piece category of the game
                 * @ default_board_config : Array with the initial configuration at the beginning 
                 *      of the game
                 *  After the Board is created it will also apply the default board configuration
                 */
                Board(const array<const Piece*,PIECE_TYPES> &pieces_properties,
                        const array<const cell_configuration,N_DEF_PIECE> & default_board_config)
                    :pieces_properties(pieces_properties),
                    default_board_config(default_board_config)
                {
                    apply_conf_board();
                    for(int i=0;i<N_PLAYER;i++){
                        players[i]=i;
                    }
                }

                ~Board()
                {
                }

                /* METHOD : it will reset the board restoring as it was in the beginning of the 
                 *          game
                 */
                void reset_board()
                {
                    for(struct Board_cell &b : this->board)
                    {
                        b.reset();
                    }
                    apply_conf_board();
                }

                /*
                 * METHOD: insert a new piece in the board
                 * @ piece : the type of the piece to insert 
                 * @ pos : 2D position of where to put the piece
                 *      start from the left-top angle from 0,0 :
                 *          the first element indicate the colon 
                 *          the second element indicate the row
                 *  @ player : the player who own the piece
                 *
                 *  if the piece, the position, or the player does not belong to any of the array
                 *  used to create the board the method will NOT insert the piece
                 */
                void put_piece(const Piece &piece, const position pos,const unsigned int player)
                {
                    framework::Board_cell *cell = find_cell(pos);
                    if(!cell){
                        return;
                    }
                    int p_index = find_player(player);
                    if(p_index == -1){
                        return;
                    }
                    const std::string &piece_name = piece.piece_name();
                    if(find_piece_category(piece_name)){
                        cell->put_piece(piece_name, p_index);
                    }
                }

                /* METHOD: move a piece from a start_position to an end_position, if possible
                 *         A piece can be moved only by the player who own the piece
                 * RETURN : TRUE : piece moved successfully
                 *          FALSE : piece not moved and board state not changed
                 *  @ start_position : indicate the current position of the piece to move
                 *  @ end_position : indicate the desirable destination of the piece
                 *  @ player : indicate the player who is trying to move the piece
                 */
                bool try_move_piece(position &start_position, position &end_position,
                        const unsigned int player)
                {
                    Board_cell *start_cell;
                    Board_cell *dest_cell;
                    const Piece *start_piece;
                    vector<struct position> *context_to_check;
                    vector<Board_cell> pc = vector<Board_cell>(0);
                    vector<cell_configuration> secondary_effect;
                    unsigned int vector_size;
                    bool valid_move = false;

                    //cells
                    start_cell = find_cell(start_position);
                    if(!start_cell || start_cell->get_owner() != player){
                        return valid_move;
                    }
                    dest_cell = find_cell(end_position);
                    if(!dest_cell)
                    {
                        return valid_move;
                    }

                    //piece
                    start_piece = find_piece_category(start_cell->get_type());
                    if(!start_piece){
                        return valid_move;
                    }

                    //position to check   
                    context_to_check = start_piece->context_to_check(start_position,end_position,
                            start_cell->get_owner());

                    if(context_to_check){
                        vector_size = context_to_check->size();
                        //cells to check
                        for(int i =0; i < vector_size;i++)
                        {
                            Board_cell *b = find_cell(context_to_check->at(i));
                            if(!b)
                            {
                                context_to_check->clear();
                                context_to_check->shrink_to_fit();
                                delete context_to_check;
                                return false;
                            }
                            pc.push_back(*b);
                        }
                    }                  
                    //checking phase
                    if(start_piece->valid_move(pc,context_to_check,secondary_effect,history))
                    {
                        //moving piece
                        Board_cell copy_cell = Board_cell(*dest_cell);
                        dest_cell->overwrite(*start_cell);
                        start_cell->reset();
                        if(!board_peculiar_status_maintained(player)){
                            start_cell->overwrite(*dest_cell);
                            dest_cell->overwrite(copy_cell);
                            if(context_to_check){
                                context_to_check->clear();
                                context_to_check->shrink_to_fit();
                                delete context_to_check;
                            }
                            return false;
                        }
                        if(!secondary_effect.empty()){
                            for(const cell_configuration &c : secondary_effect){
                                analize_cell_configuration(c);
                            }
                        }
                        this->history.insert({
                                start_position.x,
                                start_position.y,
                                end_position.x,
                                end_position.y,
                                player,
                                start_piece->piece_name()
                                });
                        valid_move = true;
                    }
                    //free the memory
                    if(context_to_check){
                        context_to_check->clear();
                        context_to_check->shrink_to_fit();
                        delete context_to_check;
                    }
                    return valid_move;

                }

                /*METHOD: print in std output the current status of the board, it does not 
                 *        change the status of the board
                 */
                void print_board() const
                {
                    unsigned int cursor = 0;
                    for(const Board_cell & cell : board){
                        std::cout << cell << "\t";
                        cursor++;
                        if(cursor == SIDE_H){
                            std::cout << std::endl;
                            cursor =0;
                        }
                    }
                }

                /* METHOD : return the area of the board
                 *  RETURN : area 
                 */
                const unsigned int board_area()const{
                    return SIDE_V * SIDE_H;
                }

                virtual bool board_peculiar_status_maintained(const unsigned int player) const{
                    return true;
                }
            protected:
                void apply_conf_board()
                {
                    Board_cell * cell;
                    const Piece *piece;
                    for(const cell_configuration &c : default_board_config)
                    {
                        analize_cell_configuration(c);
                    }
                }
                void apply_conf_board(const vector<cell_configuration> &board_conf)
                {
                    Board_cell * cell;
                    const Piece *piece;
                    for(const cell_configuration &c : default_board_config)
                    {
                        analize_cell_configuration(c);
                    }
                }
                
                void analize_cell_configuration(const cell_configuration &c)
                {
                    Board_cell * cell;
                    const Piece *piece;

                    cell = find_cell({c.x,c.y});
                    piece = find_piece_category(c.Piece_type);
                    if(!cell){
                        return;
                    }
                    if(c.Piece_owner == -1){
                        cell->reset();
                        return;
                    }
                    if(!piece){
                        return;
                    }
                    cell->put_piece(piece->piece_name(),c.Piece_owner);
                    cell = nullptr;
                }
                int find_player(const unsigned int player) const
                {
                    for(int i=0;i<players.size();i++){
                        if(players[i] == player){
                            return i;
                        }
                    }
                    return -1;
                }
                Board_cell *find_cell(const struct position &pos)
                {
                    const unsigned int index = pos.x + (pos.y * SIDE_V);   
                    if(index >= 0 && index > (SIDE_H * SIDE_V))
                    {
                        return nullptr;
                    }

                    return &board[index];
                }
                const Board_cell *find_cell(const struct position &pos) const
                {
                    const unsigned int index = pos.x + (pos.y * SIDE_V);   
                    if(index >= 0 && index > (SIDE_H * SIDE_V))
                    {
                        return nullptr;
                    }

                    return &board[index];
                }
                Board_cell *find_cell(const std::string piece, const unsigned int owner) const
                {
                    for(int i=0;i<SIDE_V*SIDE_H;i++){
                        if(board[i].get_type == piece && board[i].get_owner == owner){
                            return &board[i];
                        }
                    }
                    return nullptr;
                }

                const void find_piece_position(const std::string piece, 
                        const unsigned int owner, position &out) const
                {
                     for(int i=0;i<SIDE_V*SIDE_H;i++){
                        if(board[i].get_type() == piece && board[i].get_owner()==owner){
                            out = 
                            {
                                i%(int)SIDE_V,
                                i/(int)SIDE_H
                            };
                        }
                    }

                }
                const Piece *find_piece_category(const std::string &piece_type) const
                {
                    if(piece_type.empty()){
                        return nullptr;
                    }
                    for(int i=0;i<pieces_properties.size();i++)
                    {
                        if(pieces_properties.at(i)->piece_name() == piece_type){
                            return pieces_properties.at(i);
                        }
                    }
                    return nullptr;
                }
                Piece *get_piece(const position *pos)const;

                const array<const Piece *,PIECE_TYPES> pieces_properties;
                array<Board_cell,SIDE_H*SIDE_V> board;
                array<unsigned int,N_PLAYER> players;
                const array<const cell_configuration,N_DEF_PIECE> & default_board_config;
                Board_move_log history = Board_move_log();
        };
}  // namespace framework
