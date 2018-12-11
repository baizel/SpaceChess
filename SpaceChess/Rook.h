#pragma once

#include <vector>
#include "Piece.h"

class Rook : public Piece {
public:
    explicit Rook(float = 1.0f, float = 0.0, float = 0.0f);

    ~Rook() override;

    inline const std::vector<Direction> getValidDirections() const override;

protected:
    bool isValidDirection(Direction direction) const override;

private:
    //Make this static
    const std::vector<Direction> validDirs;
};
