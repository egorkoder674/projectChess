#ifndef PROJECT_MOVE_H
#define PROJECT_MOVE_H

class Move {
    int _fromRow;
    int _fromCol;
    int _toRow;
    int _toCol;
public:
    Move(int fromRow, int fromCol, int toRow, int toCol);
    int getFromRow() const;
    int getFromCol() const;
    int getToRow() const;
    int getToCol() const;
};
#endif //PROJECT_MOVE_H