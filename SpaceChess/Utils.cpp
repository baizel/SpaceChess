//
// Created by baize on 30/11/2018.
//

#include <cmath>
#include "Utils.h"

float Utils::length(float x1, float y1, float x2, float y2) {
    float deltaX = x2-x1;
    float deltaY = y2-y1;
    return sqrt((deltaX*deltaX)+(deltaY*deltaY));
}
