#pragma once
#include "include/framework/Piece.h"
#include "include/chess_game/generic_chess_piece.h"

namespace chess {
#pragma region PAWN
    class Pawn : public chess::Generic_chess_piece
    {
        public:
            Pawn();
            ~Pawn() override;
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const std::vector<framework::Board_cell> &context_array,
                    std::vector<struct framework::position> *positions)const override;

    };
#pragma endregion PAWN
#pragma region KNIGHT
    class Knight: public chess::Generic_chess_piece
    {
        public:
            Knight();
            ~Knight() override;
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const std::vector<framework::Board_cell> &context_array,
                    std::vector<struct framework::position> *positions)const override;

        private:
            bool l_movement(framework::position &start_position, framework::position &end_position) const;
    };

#pragma endregion KNIGHT
#pragma region BISHOP
    class Bishop: public chess::Generic_chess_piece
    {
        public:
            Bishop();
            ~Bishop() override;
        private:
            bool increment_conf(const int diff_x, const int diff_y,
                                int &increment_x, int &increment_y)const override;

    };

#pragma endregion BISHOP
#pragma region ROOK
    class Rook: public chess::Generic_chess_piece
    {
        public:
            Rook();
            ~Rook() override;
        private:
            bool increment_conf(const int diff_x, const int diff_y,
                                int &increment_x, int &increment_y)const override;

    };

#pragma endregion ROOK
#pragma region QUEEN
    class Queen: public chess::Generic_chess_piece
    {
        public:
            Queen();
            ~Queen() override;
    };

#pragma endregion QUEEN
#pragma region KING
    class King: public chess::Generic_chess_piece
    {
        public:
            King();
            ~King() override;
    };

#pragma endregion KING
}
