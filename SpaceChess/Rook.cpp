#include <cmath>
#include <iostream>
#include "Rook.h"

Rook::Rook(float pieceRadius, float x, float y) : Piece(pieceRadius, x, y), validDirs({NORTH, EAST, SOUTH, WEST}) {
    shape = SQUARE;
}

Rook::~Rook() = default;

const std::vector<Direction> Rook::getValidDirections() const {
    return validDirs;
}

bool Rook::isValidDirection(Direction direction) const {
    return (std::find(std::begin(validDirs), std::end(validDirs), direction) != std::end(validDirs));
}

std::ostream &Rook::format(std::ostream &out) const {
    out << "Rook at x: " << this->getPosition().x << " y: " << this->getPosition().y;
    return out;
}
