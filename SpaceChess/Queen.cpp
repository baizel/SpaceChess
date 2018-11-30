//
// Created by baize on 22/11/2018.
//

#include "Queen.h"

Queen::Queen(float boardSizeRadius) :Piece(boardSizeRadius), validDirs({NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST}) {
    shape = CIRCLE;
}

const std::vector<Direction> Queen::getValidDirections() const {
    return validDirs;
}

Queen::~Queen() = default;
