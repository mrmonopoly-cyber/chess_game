#pragma once
#include "include/framework/Piece.h"
#include "include/framework/Board_cell.h"

namespace chess{
    class Generic_chess_piece : public framework::Piece
    {
        public:
            Generic_chess_piece() = delete;
            Generic_chess_piece(const std::string name);
            Generic_chess_piece(const unsigned int range, const std::string name);
            Generic_chess_piece(const unsigned int range, const bool jump, const std::string name);
            virtual ~Generic_chess_piece() override;
            virtual std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            virtual bool valid_move(const std::vector<framework::Board_cell> & context_array,
                    std::vector<struct framework::position> *positions)const override;


        protected:
            virtual bool increment_conf(const int diff_x, const int diff_y,
                                int &increment_x, int &increment_y)const;
            bool vertical_check(const int diff_x, const int diff_y) const;
            bool horizontal_check(const int diff_x, const int diff_y) const;
            bool diagonal_check(const int diff_x, const int diff_y) const;

            const unsigned int range = 0;
            const bool jump_pieces = false;
        private:

    };
}
