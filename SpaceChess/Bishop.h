#pragma once

#include <vector>
#include "Piece.h"

/**
 * Class to repersent a bishop. Can only move diagonally and has a shape of Circle
 * Inherits from piece class
 * @author Baizel
 */
class Bishop : public Piece {
public:

    /**
     * Constructor with default value of radius= 1 and x,y =0
     */
    explicit Bishop(float = 1.0f, float = 0.0, float = 0.0f);

    /**
     * Default destructor
     */
    ~Bishop() override;

    /**
     * Override base class to return a list of valid directions
     * @return
     */
    inline const std::vector<Direction> getValidDirections() const override;

protected:
    /**
     * Method to check if a given direction is valid or not.
     * @param direction
     * @return True if valid direction
     */
    bool isValidDirection(Direction direction) const override;

private:
    /**
     * Stores valid the directions.
     */
    const std::vector<Direction> validDirs;
};

