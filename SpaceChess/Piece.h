//
// Created by baize on 22/11/2018.
//
#include <vector>

#pragma once
//Move to enums class
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
    explicit Piece(float boardSizeRadius);

    ~Piece();

    void move(float movement, Direction direction);

    bool isOverlapping(const Piece &piece) const;

protected:
    virtual const inline std::vector<Direction> getValidDirections() const = 0;

    float inline getMin(Axis axis) const;

    float inline getMax(Axis axis) const;

    float x;
    float y;
    float radius;
    PieceShape shape;

private:
    const float RANGE;
    float boardSizeRadius;

    bool isValidDirection(Direction direction);
};


