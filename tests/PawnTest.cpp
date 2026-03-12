#include <gtest/gtest.h>
#include "Board.h"

TEST(PawnTest, SimpleMove) {
    Board board;
    Pawn whitePawn(3, 0, Color::White);
    board.setPiece(3, 0, whitePawn);

    EXPECT_TRUE(whitePawn.canMove(4, 0, board));
    EXPECT_FALSE(whitePawn.canMove(4, 1, board));

    Pawn blackPawn(3, 1, Color::Black);
    board.setPiece(3, 1, blackPawn);

    EXPECT_FALSE(blackPawn.canMove(4, 1, board));
    EXPECT_TRUE(blackPawn.canMove(2, 1, board));
}

TEST(PawnTest, MoveFromStartPosition) {
    Board board;
    Pawn whitePawn(1, 0, Color::White);
    board.setPiece(1, 0, whitePawn);

    EXPECT_TRUE(whitePawn.canMove(3, 0, board));
    Move moveWhitePawn(1, 0, 3, 0);
    board.makeMove(moveWhitePawn);

    EXPECT_FALSE(whitePawn.canMove(5, 0, board));

    Pawn blackPawn(6, 1, Color::Black);
    board.setPiece(6, 1, blackPawn);

    EXPECT_TRUE(blackPawn.canMove(4, 1, board));
    Move moveBlackPawn(6, 1, 4, 1);
    board.makeMove(moveBlackPawn);

    EXPECT_FALSE(blackPawn.canMove(2, 1, board));
}

TEST(PawnTest, JumpFromStartPosition) {
    Board board;
    Pawn whitePawn(1, 0, Color::White);
    board.setPiece(1, 0, whitePawn);
    board.setPiece(2, 0, Rook(2, 0, Color::Black));

    EXPECT_FALSE(whitePawn.canMove(3, 0, board));

    Pawn blackPawn(6, 1, Color::Black);
    board.setPiece(6, 1, blackPawn);
    board.setPiece(5, 1, Rook(5, 1, Color::White));

    EXPECT_FALSE(blackPawn.canMove(4, 1, board));
}

TEST(PawnTest, Taking) {
    Board board;
    Pawn whitePawn(1, 1, Color::White);
    board.setPiece(1, 1, whitePawn);
    board.setPiece(2, 0, Pawn(2, 0, Color::Black));
    board.setPiece(2, 2, Pawn(2, 2, Color::Black));

    EXPECT_TRUE(whitePawn.canMove(2, 1, board));
    EXPECT_TRUE(whitePawn.canMove(2, 2, board));

    Pawn blackPawn(6, 1, Color::Black);
    board.setPiece(6, 1, blackPawn);
    board.setPiece(5, 0, Pawn(5, 0, Color::Black));
    board.setPiece(5, 2, Pawn(5, 2, Color::White));

    EXPECT_FALSE(blackPawn.canMove(5, 0, board));
    EXPECT_TRUE(blackPawn.canMove(5, 2, board));
}