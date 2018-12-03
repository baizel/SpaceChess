#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include <random>


///* wrap x -> [0,max) */
//float wrapMax(float x, float max) {
//    /* integer math: `(max + x % max) % max` */
//    return fmod(max + fmod(x, max), max);
//}
//
///* wrap x -> [min,max) */
//float wrapMinMax(float x, float min, float max) {
//    float wrapedMax = wrapMax(x - min, max - min);
//    float comp = 0.00f - wrapedMax;
////    printf("Wrap max: %.2f min: %.2f, comp: %.2f",wrapedMax,min,comp);
//    return min + wrapedMax;
//}

const static float PIECE_RADIUS = 1.0f;
const static float BOARD_RADIUS = 10.0f;

const static float LOWER_RANDOM_MOVEMENT = 0.0f;
const static float UPPER_RANDOM_MOVEMENT = 2.0f;

const static int NUMBER_OF_EACH_PIECE = 100;
const static int ROUNDS = 100;


std::mt19937 getGenerator() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    return eng;

}

void initPieces(std::vector<Piece*> &pieces) {
    std::mt19937 eng = getGenerator();
    for (int i = 0; i < NUMBER_OF_EACH_PIECE; ++i) {
        std::uniform_real_distribution<float> distribution(BOARD_RADIUS * -1, BOARD_RADIUS);
        pieces.push_back(new Queen(PIECE_RADIUS, distribution(eng), distribution(eng)));
        pieces.push_back(new Rook(PIECE_RADIUS, distribution(eng), distribution(eng)));
        pieces.push_back(new Bishop(PIECE_RADIUS, distribution(eng), distribution(eng)));
    }
}

void moveRandomAmount(Piece &piece) {
    std::mt19937 eng = getGenerator();

    std::vector<Direction> directions = piece.getValidDirections();

    std::uniform_int_distribution<> directionRange(0, directions.size() - 1);
    std::uniform_real_distribution<float> movementRange(LOWER_RANDOM_MOVEMENT, UPPER_RANDOM_MOVEMENT);

    float move = movementRange(eng);
    Direction randomDir = directions[directionRange(eng)];

    piece.move(move, randomDir);
}

int main() {
    std::vector<Piece*> pieces;
    initPieces(pieces);
    for (int i=0; i< ROUNDS; ++i){
        //TODO: stop mutating vector when iterating through it
        for (unsigned int j = 0; j < pieces.size(); ++j){
            moveRandomAmount(*pieces[j]);
            for (unsigned int k =0; k < pieces.size(); ++k){
                if (pieces[j]->isOverlapping(*pieces[k]) && j!=k){
                    // printf("Collision! %s (at position x: %2f y: %2f) is taking %s (at position x: %2f y: %2f) \n",
                    //        "TODO", pieces[j]->getPoistion().x,pieces[j]->getPoistion().y,"TODO",pieces[k]->getPoistion().x,pieces[k]->getPoistion().y);
                    pieces.erase(pieces.begin()+k);

                }

            }
        }
    }

    return 0;
}
