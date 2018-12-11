//
// Created by baize on 22/11/2018.
//

#include "Queen.h"

Queen::Queen(float pieceRadius, float x, float y) : Piece(pieceRadius, x, y), validDirs(
        {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST}) {
    shape = CIRCLE;
}

Queen::~Queen() = default;

const std::vector<Direction> Queen::getValidDirections() const {
    return validDirs;
}

bool Queen::isValidDirection(Direction direction) const {
    return (std::find(std::begin(validDirs), std::end(validDirs), direction) != std::end(validDirs));
}

std::ostream &Queen::format(std::ostream &out) const{
    out<< "Queen at x: "<< this->getPosition().x << " y: "<< this->getPosition().y;
    return out;
}

