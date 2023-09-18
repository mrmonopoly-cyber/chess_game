#ifndef _CHESS_PIECES_
#define _CHESS_PIECES_

#include "include/framework/Piece.h"

namespace chess {
#pragma region PAWN
    class Pawn : public framework::Piece
    {
        public:
            Pawn();
            ~Pawn();
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> positions,
                    const unsigned int size)const override;

    };
#pragma endregion PAWN
#pragma region KNIGHT
    class Knight: public framework::Piece
    {
        public:
            Knight();
            ~Knight();
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> positions,
                    const unsigned int size)const override;

        private:
            bool l_movement(framework::position &start_position, framework::position &end_position) const;
    };

#pragma endregion KNIGHT
#pragma region BISHOP
    class Bishop: public framework::Piece
    {
        public:
            Bishop();
            ~Bishop();
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> positions,
                    const unsigned int size)const override;

    };

#pragma endregion BISHOP
#pragma region ROOK
    class Rook: public framework::Piece
    {
        public:
            Rook();
            ~Rook();
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> positions,
                    const unsigned int size)const override;

    };

#pragma endregion ROOK
#pragma region QUEEN
    class Queen: public framework::Piece
    {
        public:
            Queen();
            ~Queen();
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> positions,
                    const unsigned int size)const override;

    };

#pragma endregion QUEEN
#pragma region KING
    class King: public framework::Piece
    {
        public:
            King();
            ~King();
            std::vector<struct framework::position> *context_to_check(
                    framework::position &start_position, framework::position &end_position,
                    const unsigned int owner)const override;
            bool valid_move(const struct framework::Board_cell ** context_array,
                    std::vector<struct framework::position> positions,
                    const unsigned int size)const override;

    };

#pragma endregion KING
}


#endif //!_CHESS_PIECES_
