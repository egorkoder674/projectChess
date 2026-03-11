#include <gtest/gtest.h>
#include "Board.h"

TEST(KingTest, SimpleMove) {
    Board board;
    King whiteKing(3, 3, Color::White);
    board.setPiece(3, 3, whiteKing);

    EXPECT_TRUE(whiteKing.canMove(4, 3, board));
    EXPECT_TRUE(whiteKing.canMove(4, 4, board));

    EXPECT_FALSE(whiteKing.canMove(3, 5, board));
    EXPECT_FALSE(whiteKing.canMove(1, 3, board));
}

TEST(KingTest, Taking) {
    Board board;
    King whiteKing(3, 3, Color::White);
    board.setPiece(3, 3, whiteKing);
    board.setPiece(2, 3, Pawn(2, 3, Color::Black));

    EXPECT_TRUE(whiteKing.canMove(2, 3, board));
    board.setPiece(2, 7, Rook(2, 7, Color::Black));
    EXPECT_FALSE(whiteKing.canMove(2, 3, board));
}

TEST(KingTest, Сastling) {
    Board board;
    King blackKing(0, 4, Color::Black);
    board.setPiece(0, 4,blackKing);
    Rook blackRookLong(0,0, Color::Black);
    board.setPiece(0,0,blackRookLong);
    Rook blackRookShort(0, 7, Color::Black);
    board.setPiece(0,7,blackRookShort);

    EXPECT_TRUE(blackKing.canMove(0, 2, board));
    EXPECT_TRUE(blackKing.canMove(0, 6, board));

    board.setPiece(1,2, Rook(1, 2, Color::White));
    board.setPiece(1,5, Rook(1, 5, Color::White));

    EXPECT_FALSE(blackKing.canMove(0, 2, board));
    EXPECT_FALSE(blackKing.canMove(0, 6, board));
}

TEST(KingTest, CastlingUnderCheck) {
    Board board;
    King blackKing(0, 4, Color::Black);
    board.setPiece(0, 4,blackKing);
    Rook blackRook(0,0, Color::Black);
    board.setPiece(0,0,blackRook);
    Rook whiteRook(4, 4, Color::White);
    board.setPiece(4,7,whiteRook);

    EXPECT_FALSE(blackKing.canMove(0, 2, board));
}