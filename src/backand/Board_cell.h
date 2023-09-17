#ifndef _BOARD_CELL
#define _BOARD_CELL
#include <string>

struct position{
        const unsigned int x;
        const unsigned int y;
    };

namespace bacbackand{
    struct board_cell{
        std::string piece_type;
        unsigned int owner;
        bool never_moved = true;
    };
};
#endif //!_BOARD_CELL
