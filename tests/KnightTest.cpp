#include <gtest/gtest.h>
#include "Board.h"

TEST(KnightTest, SimpleMove) {
    Board board;
    Knight whiteKnight(2, 2, Color::White);
    board.setPiece(2, 2, whiteKnight);

    EXPECT_TRUE(whiteKnight.canMove(0, 1, board));
    EXPECT_TRUE(whiteKnight.canMove(0, 3, board));
    EXPECT_TRUE(whiteKnight.canMove(1, 0, board));
    EXPECT_TRUE(whiteKnight.canMove(3, 0, board));
    EXPECT_TRUE(whiteKnight.canMove(4, 1, board));
    EXPECT_FALSE(whiteKnight.canMove(0, 0, board));
}

TEST(KnightTest, Taking) {
    Board board;
    Knight blackKnight(0, 0, Color::Black);
    board.setPiece(0,0,blackKnight);
    Pawn enemy(2, 1, Color::White);
    board.setPiece(2, 1, enemy);
    Pawn ally(1, 2, Color::Black);
    board.setPiece(1, 2, ally);

    EXPECT_TRUE(blackKnight.canMove(2, 1, board));
    EXPECT_FALSE(blackKnight.canMove(1, 2, board));
}

TEST(KnghtTest, CanJump) {
    Board board;
    Knight blackKnight(0, 0, Color::Black);
    board.setPiece(0,0,blackKnight);
    Pawn enemy(2, 1, Color::White);
    board.setPiece(2, 1, enemy);
    Pawn ally(1, 0, Color::Black);
    board.setPiece(1, 0, ally);

    EXPECT_TRUE(blackKnight.canMove(2, 1, board));
}