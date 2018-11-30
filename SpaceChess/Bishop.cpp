#include "Bishop.h"

Bishop::Bishop(float boardSizeRadius) : Piece(boardSizeRadius), validDirs({SOUTH_EAST, SOUTH_WEST, NORTH_EAST, NORTH_WEST}) {
    shape = CIRCLE;
}

Bishop::~Bishop() = default;

const std::vector<Direction> Bishop::getValidDirections() const {
    return validDirs;
};


