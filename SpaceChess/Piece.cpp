#include "Piece.h"
#include "Utils.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

const static float M_PI = 3.14159265358979323846f; //cmath is not working 

Piece::Piece(float pieceRadius, float x, float y) : position(x, y), radius(pieceRadius),
                                                    shape(UNKNOWN_SHAPE), toBeDeleted(false) {}

Piece::~Piece() = default;

void Piece::move(float movement, Direction direction, float boundaryRadius, bool isBounded) {
    if (isValidDirection(direction)) {
        position.x += movement * (float) sin((direction * M_PI) / 180);
        position.y += movement * (float) cos((direction * M_PI) / 180);
        if (isBounded ) {
            if (boundaryRadius <=0.0){
                throw std::invalid_argument("Boundary Radius cannot be less than or equal to 0");
            }
            if (position.x > boundaryRadius) {
                position.x = boundaryRadius;
            }
            if (position.x < boundaryRadius * -1) {
                position.x = boundaryRadius * -1;
            }
            if (position.y > boundaryRadius) {
                position.y = boundaryRadius;
            }
            if (position.y < boundaryRadius * -1) {
                position.y = boundaryRadius * -1;
            }
        }

    } else {
        throw std::invalid_argument("Invalid direction");
    }
}

bool Piece::isOverlapping(const Piece &piece) const {
    if (piece.shape == CIRCLE && shape == CIRCLE) {
        return circleCollision(piece);

    } else if (piece.shape == SQUARE && shape == SQUARE) {
        return squareCollision(piece);

    } else if ((piece.shape == SQUARE || piece.shape == CIRCLE) && (shape == CIRCLE || shape == SQUARE)) {
        return circleSquareCollision(piece);

    } else {
        throw std::invalid_argument("Invalid Shape enum");
    }
}

bool Piece::circleCollision(const Piece &piece) const {
    float deltaX = position.x - piece.position.x;
    float deltaY = position.y - piece.position.y;

    float lengthFromCenter = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    return lengthFromCenter < (radius + piece.radius);
}

bool Piece::squareCollision(const Piece &piece) const {
    bool xAxisCheck = (getMinAxis(X) >= piece.getMinAxis(X) && piece.getMinAxis(X) <= getMaxAxis(X)) ||
                      (getMinAxis(X) >= piece.getMinAxis(X) && piece.getMinAxis(X) <= getMaxAxis(X));

    bool yAxisCheck = (getMinAxis(Y) >= piece.getMinAxis(Y) && piece.getMinAxis(Y) <= getMaxAxis(Y)) ||
                      (getMinAxis(Y) >= piece.getMinAxis(Y) && piece.getMinAxis(Y) <= getMaxAxis(Y));

    return xAxisCheck && yAxisCheck;
}

bool Piece::circleSquareCollision(const Piece &piece) const {
    const Piece &circle = piece.shape == CIRCLE ? piece : *this;
    const Piece &square = piece.shape == SQUARE ? piece : *this;

    float circleX = abs(circle.position.x - square.position.x);
    float circleY = abs(circle.position.y - square.position.y);

    if (circleX > (square.radius + circle.radius)) { return false; }
    if (circleY > (square.radius + circle.radius)) { return false; }

    if (circleX <= square.radius) { return true; }
    if (circleY <= square.radius) { return true; }

    float cornerDistance_sq = ((circleX - square.radius) * (circleX - square.radius)) +
                              ((circleY - square.radius) * (circleY - square.radius));

    return (cornerDistance_sq <= (circle.radius * circle.radius));
}

float inline Piece::getMinAxis(Axis axis) const {
    switch (axis) {
        case (X):
            return position.x - radius;
        case (Y):
            return position.y - radius;
        default:
            //TODO: throw err
            return NULL;
    }
}

float inline Piece::getMaxAxis(Axis axis) const {
    switch (axis) {
        case (X):
            return position.x + radius;
        case (Y):
            return position.y + radius;
        default:
            //TODO: throw err
            return NULL;
    }
}

const Position Piece::getPoistion() const {
    return position;
}



