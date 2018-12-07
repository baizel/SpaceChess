#pragma once
#include "Position.h"
#include "Directions.h"
#include "PieceShape.h"
#include "Axis.h"

#include <vector>



class Piece {
public:

    explicit Piece(float = 1.0f, float = 0.0, float = 0.0f);

    virtual ~Piece();

    void move(float movement, Direction direction, float = 0.0f, bool = false);

    bool isOverlapping(const Piece &piece) const;

    const Position getPoistion() const;

    virtual const inline std::vector<Direction> getValidDirections() const = 0;

    bool toBeDeleted;

protected:

    float radius;
    PieceShape shape;


    virtual bool isValidDirection(Direction direction) const = 0;

    /**
     * Assumes no rotation is applied ot the shape
     * @param axis
     * @return
     */
    float inline getMinAxis(Axis axis) const;

    float inline getMaxAxis(Axis axis) const;


private:
    Position position;

    bool circleSquareCollision(const Piece &piece) const;

    bool squareCollision(const Piece &piece) const;

    bool circleCollision(const Piece &piece) const;
};


