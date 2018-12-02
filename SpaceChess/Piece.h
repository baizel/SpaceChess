//
// Created by baize on 22/11/2018.
//
#include <vector>

#pragma once

//Move to enums class
struct Position {
    float x;
    float y;

    Position(float x, float y) : x(x), y(y) {}

};

enum PieceShape {
    SQUARE,
    CIRCLE,
    UNKNOWN_SHAPE
};
enum Direction {
    NORTH = 0,
    NORTH_EAST = 45,
    EAST = 90,
    SOUTH_EAST = 135,
    SOUTH = 180,
    SOUTH_WEST = 225,
    WEST = 270,
    NORTH_WEST = 315,
    UNKNOWN_DIRECTION
};
enum Axis {
    X, Y
};

class Piece {
public:
    explicit Piece(float = 1.0f ,float = 0.0, float = 0.0f);

    ~Piece();

    void move(float movement, Direction direction);

    bool isOverlapping(const Piece &piece) const;
    const Position getPoistion() const;
protected:

    float radius;
    PieceShape shape;

    virtual const inline std::vector<Direction> getValidDirections() const = 0;

    virtual bool isValidDirection(Direction direction) const = 0;

    float inline getMinAxis(Axis axis) const;

    float inline getMaxAxis(Axis axis) const;


private:
    Position position;


    bool circleSquareCollision(const Piece &piece) const;

    bool squareCollision(const Piece &piece) const;

    bool circleCollision(const Piece &piece) const;
};


