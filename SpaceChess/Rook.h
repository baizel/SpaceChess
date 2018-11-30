//
// Created by baize on 22/11/2018.
//
#pragma once

#include <vector>
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(float boardSizeRadius);

    ~Rook();

protected:
    inline const std::vector<Direction> getValidDirections() const override;

private:
    //Make this static
    const std::vector<Direction> validDirs;
};
