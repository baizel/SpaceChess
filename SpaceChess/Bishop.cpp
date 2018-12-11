#include "Bishop.h"

Bishop::Bishop(float pieceRadius, float x, float y) :
        Piece(pieceRadius, x, y), validDirs({SOUTH_EAST, SOUTH_WEST, NORTH_EAST, NORTH_WEST}) {
    shape = CIRCLE;
}

Bishop::~Bishop() = default;

const std::vector<Direction> Bishop::getValidDirections() const {
    return validDirs;
};

bool Bishop::isValidDirection(Direction direction) const {
    return (std::find(std::begin(validDirs), std::end(validDirs), direction) != std::end(validDirs));
}

std::ostream &Bishop::format(std::ostream &out) const{
    out<< "Bishop at x: "<< this->getPosition().x << " y: "<< this->getPosition().y;
    return out;
}

