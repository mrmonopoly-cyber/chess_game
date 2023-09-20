#ifndef _BOARD_CELL
#define _BOARD_CELL
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
            bool is_empty()const;
            bool no_moved() const;
            void reset();
            unsigned int get_owner()const;
            const std::string &get_type() const;
            void overwrite(Board_cell &cell);
            void put_piece(const std::string &piece_name, const unsigned int owner);
            friend std::ostream& operator<<(std::ostream &stream, const framework::Board_cell &board_cell);
        private:
            std::string piece_type = "";
            unsigned int owner = 0;
            bool never_moved = true;
    };
std::ostream& operator<<(std::ostream &stream, const framework::Board_cell &board_cell);
}

#endif //!_BOARD_CELL
