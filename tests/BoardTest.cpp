#include <gtest/gtest.h>
#include "Board.h"

TEST(BoardTest, SimpleCheck) {
    Board board;
    board.setPiece(5, 4, Pawn(5,4, Color::White));

    EXPECT_TRUE(std::holds_alternative<Pawn>(board.getPiece(5, 4)));
    EXPECT_TRUE(board.isOccupied(5, 4));
}

TEST(BoardTest, BoardMove) {
    Board board;
    board.setPiece(0, 0, Rook(0, 0, Color::White));
    Move move(0,0,5,0);

    EXPECT_TRUE(board.isLegalMove(move));
}

TEST(BoardTest, CellUnderAttack) {
    Board board;
    board.setPiece(5,4,King(5,4, Color::White));
    board.setPiece(5, 0, Rook(5,0,Color::Black));

    EXPECT_TRUE(board.cellUnderAttack(5, 4, Color::White));
    EXPECT_FALSE(board.cellUnderAttack(5, 5, Color::White));
}

TEST(BoardTest, CullUnderAttackWithBlock) {
    Board board;
    board.setPiece(0,0,King(5,4, Color::White));
    board.setPiece(2,0,Pawn(2,0,Color::White));
    board.setPiece(5, 0, Rook(5,0,Color::Black));

    EXPECT_FALSE(board.cellUnderAttack(0, 0, Color::White));
}
