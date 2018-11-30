//
// Created by baize on 22/11/2018.
//
#pragma once

#include <vector>
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(float boardSizeRadius);

    ~Queen();

protected:
    inline const std::vector<Direction> getValidDirections() const override;

private:
    const std::vector<Direction> validDirs;
};
