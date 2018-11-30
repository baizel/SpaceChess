#include <cmath>
#include <iostream>
#include "Rook.h"

Rook::Rook(float boardSizeRadius) : Piece(boardSizeRadius), validDirs({NORTH, EAST, SOUTH, WEST}) {
    shape = SQUARE;
}

Rook::~Rook() = default;

const std::vector<Direction> Rook::getValidDirections() const {
    return validDirs;
}
