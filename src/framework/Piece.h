#pragma once
/*
 * author : Alberto Damo
 * date : 2023-09-20
 *
 * Interface to create the piece of the board game. To define new pieces you can inherit this 
 * object. 
 */
#include <string>
#include <vector>

#include "Board_cell.h"

namespace framework {
    class Piece {
        public:
            Piece() = delete;
            Piece(const std::string &name);
            virtual ~Piece();
            const std::string &piece_name() const;

            /*
             * METHOD: it's used to determine which cell of the board needs to be checked to 
             * make the move. Can return nullptr
             * RETURN: vector pointer with the positions of all the cells to be checked
             * @ start_position : starting position of the piece to move
             * @ end_position : destination of the piece to move
             * @ owner : player that is doing the move
             */
            virtual std::vector<struct position> *context_to_check(
                    position &start_position, position &end_position,
                    const unsigned int owner)const =0;

            /*
             * METHOD: determine if a move is valid, analyzing the content of the cells and 
             * the position of the cells
             * RETURN : TRUE : valid move
             *          FALSE : invalid move
             */
            virtual bool valid_move(const std::vector<Board_cell> &context_array,
                    std::vector<struct framework::position> *positions)const =0;
    
        protected:
            const std::string name;
    };
}
