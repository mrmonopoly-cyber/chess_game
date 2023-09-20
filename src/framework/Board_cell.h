#pragma once
/*
 * Author : Alberto Damo
 * Date : 2023-09-21
 */
#include <ostream>
#include <string>
#include <iostream>

namespace framework{
    struct cell_configuration
    {
        const unsigned int x;
        const unsigned int y;
        const unsigned int Piece_index;
        const unsigned int Piece_owner;
    };
    struct position{
        unsigned int x;
        unsigned int y;
    };
    class Board_cell{
        public:
            Board_cell();
            /*
             * METHOD: return true if the cell is unoccupied 
             */
            bool is_empty()const;
            /*
             * METHOD : return true if the cell has never be altered since the beginning of 
             * the game
             */
            bool no_moved() const;
            /*
             * METHOD: restore the cell to an empty cell which was never used
             */
            void reset();
            /*
             * METHOD: return the player of the piece in the current cell
             */
            unsigned int get_owner()const;
            /*
             * METHOD: return the name of the piece in the cell
             */
            const std::string &get_type() const;
            /*
             * METHOD: overwrite the status of the cell with a new one
             */
            void overwrite(Board_cell &cell);
            /*
             * METHOD: put a piece in the current cell
             * @ piece_name : name of the piece type to put
             * @ owner : player that is controlling the piece
             */
            void put_piece(const std::string &piece_name, const unsigned int owner);
            /*
             * METHOD: print the content of the cell in the form of:
             *          [PIECE_NAME][OWNER]
             */
            friend std::ostream& operator<<(std::ostream &stream, const framework::Board_cell &board_cell);
        private:
            std::string piece_type = "";
            unsigned int owner = 0;
            bool never_moved = true;
    };
std::ostream& operator<<(std::ostream &stream, const framework::Board_cell &board_cell);
}
