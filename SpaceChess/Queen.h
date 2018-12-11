#pragma once

#include <vector>
#include "Piece.h"

class Queen : public Piece {
public:
    explicit Queen(float = 1.0f, float = 0.0, float = 0.0f);

    ~Queen() override;

    inline const std::vector<Direction> getValidDirections() const override;

protected:
    bool isValidDirection(Direction direction) const override;

private:
    const std::vector<Direction> validDirs;
};
