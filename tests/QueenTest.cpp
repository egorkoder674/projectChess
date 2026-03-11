#include <gtest/gtest.h>
#include "Board.h"

TEST(QueenTest, SimpleMove) {
    Board board;
    Queen whiteQueen(3, 3, Color::White);

    EXPECT_TRUE(whiteQueen.canMove(0,0, board));
    EXPECT_TRUE(whiteQueen.canMove(2,4, board));
    EXPECT_TRUE(whiteQueen.canMove(6, 3, board));
    EXPECT_TRUE(whiteQueen.canMove(3, 6, board));
    EXPECT_FALSE(whiteQueen.canMove(4, 5, board));
    EXPECT_FALSE(whiteQueen.canMove(5, 0, board));
}

TEST(QueenTest, Taking) {
    Board board;
    Queen whiteQueen(3, 3, Color::White);
    board.setPiece(3, 3, whiteQueen);
    board.setPiece(0,0,Pawn(0,0,Color::Black));
    board.setPiece(2,4,Pawn(2,4,Color::White));
    board.setPiece(6,3,Pawn(6,3,Color::Black));
    board.setPiece(5,0,Pawn(5,0,Color::Black));

    EXPECT_TRUE(whiteQueen.canMove(0,0, board));
    EXPECT_FALSE(whiteQueen.canMove(2,4, board));
    EXPECT_TRUE(whiteQueen.canMove(6, 3, board));
    EXPECT_FALSE(whiteQueen.canMove(5, 0, board));
}

TEST(QueenTest, CannotJump) {
    Board board;
    Queen whiteQueen(3, 3, Color::White);
    board.setPiece(3, 3, whiteQueen);
    board.setPiece(3, 5, Pawn(3,5, Color::White));
    board.setPiece(3,7,Pawn(3, 7, Color::Black));

    EXPECT_FALSE(whiteQueen.canMove(3, 7, board));

    board.setPiece(5, 3, Pawn(5,3,Color::Black));
    board.setPiece(7, 3, Pawn(7, 3, Color::Black));

    EXPECT_FALSE(whiteQueen.canMove(7,3, board));

    board.setPiece(2, 2, Pawn(2,2, Color::White));
    board.setPiece(0, 0, Pawn(0, 0, Color::Black));

    EXPECT_FALSE(whiteQueen.canMove(0,0, board));
}