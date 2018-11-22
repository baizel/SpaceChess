//
// Created by baize on 22/11/2018.
//
#pragma once
enum PieceShape {
    SQUARE,
    CIRCLE
};
class Piece {
public:
    Piece();
    ~Piece();
    virtual void moveForward() = 0;
private:
    int radius;
    PieceShape shape;
};


