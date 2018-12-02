#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"

/* wrap x -> [0,max) */
float wrapMax(float x, float max) {
    /* integer math: `(max + x % max) % max` */
    return fmod(max + fmod(x, max), max);
}

/* wrap x -> [min,max) */
float wrapMinMax(float x, float min, float max) {
    float wrapedMax = wrapMax(x - min, max - min);
    float comp = 0.00f - wrapedMax;
//    printf("Wrap max: %.2f min: %.2f, comp: %.2f",wrapedMax,min,comp);
    return min + wrapedMax;
}

int main() {
    Queen queen(1.0f);
    printf("\nR: %2f",queen.getPoistion().y);
    queen.move(2.000001f, SOUTH_WEST);

    Bishop b(1.0f);
//    b.move(1.1f,NORTH_EAST);
    printf("\nOverlap : %d PLS\n", b.isOverlapping(queen));

//    printf("wrapped: %.2f", wrapMinMax(4.0f, -4.0f, 4.0f));
    return 0;
}
