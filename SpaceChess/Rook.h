#pragma once

#include <vector>
#include "Piece.h"
/**
 * Class for Bishop inherited from piece. Shape is a Square and can only move up, down, left, right
 * @author Baizel
 */

class Rook : public Piece {
public:
    /**
   * Constructor with default value of radius= 1 and x,y =0
   */
    explicit Rook(float = 1.0f, float = 0.0, float = 0.0f);

    /**
     * Default destructor
     */
    ~Rook() override;

    /**
     * Override base class to return a list of valid directions
     * @return list of valid directions
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
     * Holds the Valid directions
     */
    const std::vector<Direction> validDirs;

    /**
     * Function to format output data when using cout
     * @param out
     * @param obj
     * @return ostream
     */
    std::ostream &format(std::ostream &out) const override;
};
