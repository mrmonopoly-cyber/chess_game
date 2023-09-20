#ifndef _PIECES_
#define _PIECES_
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

            virtual std::vector<struct position> *context_to_check(
                    position &start_position, position &end_position,
                    const unsigned int owner)const =0;
            virtual bool valid_move(const std::vector<Board_cell> &context_array,
                    std::vector<struct framework::position> *positions)const =0;
    
        protected:
            const std::string name;
    };
}
#endif //!_PIECES_
