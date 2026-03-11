#include <gtest/gtest.h>
#include "Board.h"
#include "Bishop.h"

TEST(BishopTest, SimpleMove) {
    Board board;
    Bishop whiteBishop(7,2, Color::White);
    board.setPiece(7,2,whiteBishop);

    EXPECT_TRUE(whiteBishop.canMove(5, 4, board));
    EXPECT_FALSE(whiteBishop.canMove(5, 5, board));
    EXPECT_FALSE(whiteBishop.canMove(0, 4, board));
}

TEST(BishopTest, Taking) {
    Board board;
    Bishop whiteBishop(7, 2, Color::White);
    board.setPiece(7, 2, whiteBishop);

    Pawn blackPawn(6, 3, Color::Black);
    board.setPiece(6, 3, blackPawn);

    EXPECT_TRUE(whiteBishop.canMove(6, 3, board));
    EXPECT_FALSE(whiteBishop.canMove(2, 7, board));
}

TEST(BishopTest, CannotJump) {
    Board board;
    Bishop whiteBishop(7, 2, Color::White);
    board.setPiece(7, 2, whiteBishop);

    Pawn whitePawn(6, 3, Color::White);
    board.setPiece(6, 3, whiteBishop);

    Pawn blackPawn(5,4, Color::Black);
    board.setPiece(5, 4, blackPawn);

    EXPECT_FALSE(whiteBishop.canMove(5, 4, board));
    EXPECT_FALSE(whiteBishop.canMove(2, 7, board));
}