//
// Created by baize on 22/11/2018.
//
#pragma once

#include <vector>
#include "Piece.h"

class Queen : public Piece {
public:
    explicit Queen(float = 1.0f ,float = 0.0, float = 0.0f);

    ~Queen();

protected:
    inline const std::vector<Direction> getValidDirections() const override;

    bool isValidDirection(Direction direction) const override;

private:
    const std::vector<Direction> validDirs;
};
