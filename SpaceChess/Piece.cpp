//
// Created by baize on 22/11/2018.
//
#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "Piece.h"
#include "Utils.h"

Piece::Piece(float boardSizeRadius) : x(0.0f), y(0.0f), radius(1.0f), boardSizeRadius(boardSizeRadius),
                                      RANGE((boardSizeRadius * 2) + 1),shape(UNKNOWN_SHAPE) {}

Piece::~Piece() = default;

bool Piece::isValidDirection(Direction direction) {
    //TODO: make this pure virtual
    std::vector<Direction> dir = getValidDirections();
    return (std::find(std::begin(dir), std::end(dir), direction) != std::end(dir));
}

void Piece::move(float movement, Direction direction) {
    if (isValidDirection(direction)) {
        x += movement * (float) sin((direction * M_PI) / 180);
        y += movement * (float) cos((direction * M_PI) / 180);

        printf("x: %.2f y: %2f", x, y);
    } else {
        std::cout << "REEEEEEEEEEEEEEEEEE";
        // throw std::invalid_argument("Invalid direction");
    }
}

bool Piece::isOverlapping(const Piece &piece) const {
    if (piece.shape == CIRCLE && shape == CIRCLE) {
        float deltaX = x - piece.x;
        float deltaY = y - piece.y;

        float lengthFromCenter = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
        return lengthFromCenter < (radius + piece.radius);

    } else if (piece.shape == SQUARE && shape == SQUARE) {
        bool xAxisCheck = (getMin(X) >= piece.getMin(X) && piece.getMin(X) <= getMax(X)) ||
                          (getMin(X) >= piece.getMin(X) && piece.getMin(X) <= getMax(X));

        bool yAxisCheck = (getMin(Y) >= piece.getMin(Y) && piece.getMin(Y) <= getMax(Y)) ||
                          (getMin(Y) >= piece.getMin(Y) && piece.getMin(Y) <= getMax(Y));

        return xAxisCheck && yAxisCheck;

    } else if ((piece.shape == SQUARE || piece.shape == CIRCLE) && (shape == CIRCLE || shape == SQUARE)) {
        // TODO: Do this but like not copy stack overflow
        const Piece &circle = piece.shape == CIRCLE ? piece : *this;
        const Piece &square = piece.shape == SQUARE ? piece : *this;

        float circleX = abs(circle.x - square.x);
        float circleY = abs(circle.y - square.y);

        if (circleX > (square.radius + circle.radius)) { return false; }
        if (circleY > (square.radius + circle.radius)) { return false; }

        if (circleX <= square.radius) { return true; }
        if (circleY <= square.radius) { return true; }

        float cornerDistance_sq = ((circleX - square.radius) * (circleX - square.radius)) +
                                  ((circleY - square.radius) * (circleY - square.radius));

        return (cornerDistance_sq <= (circle.radius * circle.radius));

    } else {
        throw std::invalid_argument("Invalid Shape enum");
    }
}

float inline Piece::getMin(Axis axis) const {
    switch (axis) {
        case (X):
            return x - radius;
        case (Y):
            return y - radius;
        default:
            //TODO: throw err
            return NULL;
    }
}

float inline Piece::getMax(Axis axis) const {
    switch (axis) {
        case (X):
            return x + radius;
        case (Y):
            return y + radius;
        default:
            //TODO: throw err
            return NULL;
    }
}



