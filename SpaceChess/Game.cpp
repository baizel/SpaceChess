#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include <random>

const static float PIECE_RADIUS = 1.0f;
const static float BOARD_RADIUS = 20.0f;

const static float UPPER_RANDOM_MOVEMENT = 10.0f;
const static float LOWER_RANDOM_MOVEMENT = 1.0f;

const static int NUMBER_OF_EACH_PIECE = 100;
const static int ROUNDS = 1000;
const static bool IS_BOUNDED_TO_BOARD = true;

static int rookCounter = 0;
static int bishopCounter = 0;
static int queenCounter = 0;

std::mt19937 getGenerator() {
    //Inspiration taken from https://stackoverflow.com/a/7560564 by Cubbi
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    return eng;

}

void initPieces(std::vector<Piece *> &pieces) {
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

    piece.move(move, randomDir, BOARD_RADIUS, IS_BOUNDED_TO_BOARD);
}

void erasePieces(std::vector<Piece *> &pieces, int j = 0) {
    int size = pieces.size();
    for (int i = size - 1; i >= 0; --i) {
        //  std::cout<<"Size: "<<pieces.size() <<" i: " <<i <<"\n";
        if (pieces[i]->toBeDeleted) {
            auto &t = *pieces[i];
            if (typeid(Rook) == typeid(t)) {
                rookCounter++;
            } else if (typeid(Bishop) == typeid(t)) {
                bishopCounter++;
            } else if (typeid(Queen) == typeid(t)) {
                queenCounter++;
            }
            delete pieces[i];
            pieces.erase(pieces.begin() + i);
        }
    };
}

int main() {

    std::vector<Piece *> pieces;
    initPieces(pieces);
    for (int i = 0; i < ROUNDS && pieces.size() > 1; ++i) {
        erasePieces(pieces);
        for (unsigned int j = 0; j < pieces.size(); ++j) {
            moveRandomAmount(*pieces[j]);
            for (unsigned int k = 0; k < pieces.size(); ++k) {
                if (pieces[j]->isOverlapping(*pieces[k]) && j != k && !pieces[k]->toBeDeleted) {
                    pieces[k]->toBeDeleted = true;
                    std::cout << (*pieces[j]) << " Captured Piece " << (*pieces[k]) <<std::endl;
                }
            }
        }
    }
    std::cout << "\nRook captured: " << rookCounter << ", Bishop captured: " << bishopCounter << ", Queen captured: "
              << queenCounter << "\n";
	float x;
	std::cin >> x;
    return 0;
}

