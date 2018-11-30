//
// Created by baize on 22/11/2018.
//
#pragma once

#include <vector>
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(float boardSizeRadius);

    ~Bishop();

protected:
    inline const std::vector<Direction> getValidDirections() const override;

private:
    const std::vector<Direction> validDirs;
};

