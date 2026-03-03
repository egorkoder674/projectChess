//
// Created by admin on 03.03.2026.
//

#ifndef PROJECT_ALLFIGURES_H
#define PROJECT_ALLFIGURES_H
#include <variant>
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Empty.h"

using PieceVariant = std::variant<Empty, Bishop, King, Knight, Pawn, Queen, Rook>;
#endif //PROJECT_ALLFIGURES_H