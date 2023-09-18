#ifndef _PIECES_
#define _PIECES_
#include <string>
#include <vector>

#include "Board_cell.h"

namespace framework {
    class Piece {
        public:
            Piece() = delete;
            Piece(const char *const name);
            Piece(const unsigned int range, const std::string name);
            Piece(const unsigned int range, const std::string name, const bool jump_pieces);
            ~Piece();
            std::string *piece_name() const;

            virtual std::vector<struct position> *context_to_check(
                    position &start_position, position &end_position,
                    const unsigned int owner)const;
            virtual bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> *positions,
                    const unsigned int size)const;
    
        protected:
            bool vertical_check(const position &start_position,
                    const position &end_position) const;
            bool horizontal_check(const position &start_position,
                    const position &end_position) const;
            bool diagonal_check(const position &start_position,
                    const position &end_position) const;

        protected:
            const unsigned int range = 0;
            const std::string name;
            const bool jump_pieces = false;
    };
}
#endif //!_PIECES_
