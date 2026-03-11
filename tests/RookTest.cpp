#include <gtest/gtest.h>
#include "Board.h"
#include "Rook.h"

TEST(RookTest, SimpleMove) {
    Board board;
    Rook whiteRook(5, 4, Color::White);
    board.setPiece(5, 4, whiteRook);

    EXPECT_TRUE(whiteRook.canMove(0, 4, board));
    EXPECT_FALSE(whiteRook.canMove(0,0,board));
}

TEST(RookTest, Taking) {
    Board board;
    Rook whiteRook(0, 0, Color::White);
    board.setPiece(0,0,whiteRook);

    Rook enemy(0, 7, Color::Black);
    board.setPiece(0,7,enemy);

    EXPECT_TRUE(whiteRook.canMove(0,7, board));
}

TEST(RookTest, CannotJump) {
    Board board;
    Rook whiteRook(0, 0, Color::White);
    board.setPiece(0,0,whiteRook);

    Rook enemy(0, 7, Color::Black);
    board.setPiece(0,7,enemy);

    Pawn block(0,5,Color::Black);
    board.setPiece(0, 5, block);

    EXPECT_FALSE(whiteRook.canMove(0,7, board));
}