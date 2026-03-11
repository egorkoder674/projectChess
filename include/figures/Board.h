#pragma once
#include <vector>
#include <variant>
#include "Empty.h"
#include "Move.h"
#include "Color.h"
#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include <cmath>

class Bishop;
class King;
class Knight;
class Queen;
class Rook;
class Pawn;

using PieceVariant = std::variant<Empty, Bishop, King, Knight, Pawn, Queen, Rook>;

class Board {
    std::vector<std::vector<PieceVariant>> data;
public:
    Board();
    bool isOccupied(int row, int col) const;
    const PieceVariant& getPiece(int row, int col) const;
    bool cellUnderAttack(int row, int col, Color ColorOfMoved) const;
    void setPiece(int row, int col, const PieceVariant& piece);
    void makeMove(const Move& move);
    bool isLegalMove(const Move& move);
    bool isInside(int row, int col) const;
};