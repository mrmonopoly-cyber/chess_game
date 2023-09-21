#pragma once

#include <string>
#include <vector>

namespace framework{

    class Board_move_log 
    {
        public:
            struct Log{
                unsigned start_x;
                unsigned start_y;
                unsigned dest_x;
                unsigned dest_y;
                unsigned int player;
                std::string piece_type;
            };
            Board_move_log();
            /*
             * METHOD: add a new Log to the system
             * @ move : move to log
             */
            void insert(const Log & move);
            /*
             * METHOD: return the last move executed
             */
            const Log *last_move() const;
            /*
             * METHOD: return the last i-th move executed
             */
            const Log *last_ith_move(unsigned int i)const;
        private:
            std::vector<Log> history = std::vector<Log>(0);
    };

}
