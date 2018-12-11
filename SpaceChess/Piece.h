#pragma once

#include "Position.h"
#include "Directions.h"
#include "PieceShape.h"
#include "Axis.h"
#include <vector>
#include <iostream>

/**
 * Abstract Class 'Piece' to represent a chess piece.
 * Stores x,y coordinate of piece and provides a method to move the piece in a given direction.
 * @Author Baizel
 */

class Piece {
public:
    /**
     * Constructor with optional prams. Default value will initialise piece with radius of 1 and x,y position  of 0,0
     */
    explicit Piece(float = 1.0f, float = 0.0, float = 0.0f);

    /**
     * Virtual destructor which is default since no Pointer are used here
     */
    virtual ~Piece();

    /**
     * Pure virtual inline function return the set of valid direction a piece can move.
     * @return a list of directions
     */
    virtual const inline std::vector<Direction> getValidDirections() const = 0;

    /**
     * Method to move a piece given a movement vector and a direction.
     * x = movement * sin(direction)
     * y = movement * cos(direction)
     * This method can bind the pieces to a boundary by giving the Boundary radius and setting isBounded to true
     * @param movement. A float to move in any given direction. Note: If a diagonal direction is given then movement will be treated as the hypotenuse
     * @param direction. A Direction enum that must be in the set of valid direction
     * @param Optional Float boundaryRadius. Float ot repersent the upper boundary from center. I.E b = 4 then boundary = -4, 4 on x & y axis
     * @param Optional Bool isBounded. Bound pieces to the boundary or not. if true then boundaryRadius cannot be 0
     */
    void move(float movement, Direction direction, float = 0.0f, bool = false);

    /**
     * Method to check if another piece is overlapping. Assumes only two valid shapes Square and Circle
     * @param piece
     * @return bool. True if overlapping
     */
    bool isOverlapping(const Piece &piece) const;

    /**
     * Getter to get the x,y coordinate of a piece
     * @returns Position struct
     */
    const Position getPosition() const;

    /**
     * Flag to mark for deletion, Use for the main Game loop
     */
    bool toBeDeleted;

    friend std::ostream &operator<<(std::ostream &outStream, const Piece &piece);

protected:
    /**
     * Using radius since the only two shape are circle and Square, both of which can have a radius.
     * Note: Square radius = 0.5 * Length
     */
    float radius;

    /**
     * Enum to determine which shape each piece is
     */
    PieceShape shape;

    /**
     * Pure virtual function to see if a given Direction is valid or not.
     * @param direction
     * @return
     */
    virtual bool isValidDirection(Direction direction) const = 0;

    /**
     * Assumes no rotation is applied ot the shape.
     * @param axis
     * @return float which is the minimum point of a given axis for a shape. Center.x||y  - Radius
     */
    float inline getMinAxis(Axis axis) const;

    /**
     * Assumes no rotation is applied ot the shape.
     * @param axis
     * @return float which is the minimum point of a given axis for a shape. Center.x||y + Radius
     */
    float inline getMaxAxis(Axis axis) const;


private:
    /**
     * Stores Position
     */
    Position position;

    /**
     * Function to format children when using cout
     * @param out
     * @param obj
     * @return ostream
     */
    virtual std::ostream& format(std::ostream &out) const = 0;

    /**
     * Assumes no rotation has applied to any of the shapes
     * Method to detect a Circle Square collision.
     * @param piece
     * @return True if given pieces collides
     */
    bool circleSquareCollision(const Piece &piece) const;

    /**
     * Assumes no rotation has applied to any of the shapes
     * Method to detect Square Square collision. Uses min and max of each square
     * @param piece
     * @return True if given pieces collides
     */
    bool squareCollision(const Piece &piece) const;

    /**
     * Method to check for Circle Circle collision
     * compares the length from the 2 center and radius added together.
     * @param piece
     * @return True if given pieces collides
     */
    bool circleCollision(const Piece &piece) const;

};


