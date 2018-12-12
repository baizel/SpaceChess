#include <iostream>
#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include <random>

/**
 * Main Game loop class
 * @author Baizel
 */

/*
 * Radius of each piece
 */
const static float PIECE_RADIUS = 1.0f;

/*
 * Board size (Center to right most size)
 */
const static float BOARD_RADIUS = 10.0f;
/*
 * Flag to set if the pieces should bounded to the board
 */
const static bool IS_BOUNDED_TO_BOARD = true;

/*
 * Upper and lower bounds of the random movement
 */
const static float UPPER_RANDOM_MOVEMENT = 10.0f;
const static float LOWER_RANDOM_MOVEMENT = 1.0f;

/*
 * Number of each pieces to be initialised on the board
 */
const static int NUMBER_OF_EACH_PIECE = 25;

/*
 * Max number of rounds to be played
 */
const static int MAX_ROUNDS = 50;

/*
 * Counter to keep track of deleted pieces
 */
static int rookCounter = 0;
static int bishopCounter = 0;
static int queenCounter = 0;

/*
 * Number of Unique pieces such as Queen, Rook, Bishop
 */
const static int NUMBER_OF_UNIQUE_PIECES = 3;

/**
 * Random number Generator
 * Inspiration taken from Cubbi (https://stackoverflow.com/a/756056)
 * @return mt19937 engine
 */
std::mt19937 getGenerator() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    return eng;

}

/**
 * Initialise all pieces with random x,y coord and a radius of 1 and store them in a vector
 * @param pieces list to be modified
 */
void initPieces(std::vector<Piece *> &pieces) {
    std::mt19937 eng = getGenerator();
    pieces.reserve(NUMBER_OF_EACH_PIECE * NUMBER_OF_UNIQUE_PIECES);
    for (int i = 0; i < NUMBER_OF_EACH_PIECE; ++i) {
        std::uniform_real_distribution<float> distribution(BOARD_RADIUS * -1, BOARD_RADIUS);
        pieces.push_back(new Queen(PIECE_RADIUS, distribution(eng), distribution(eng)));
        pieces.push_back(new Rook(PIECE_RADIUS, distribution(eng), distribution(eng)));
        pieces.push_back(new Bishop(PIECE_RADIUS, distribution(eng), distribution(eng)));
    }
}

/**
 * Moves a given piece by random amount in a random direction between the defined Lower bound and upper bound.
 * Method also bounds piece to the boundary
 * @param piece to be moved
 */
void moveRandomAmount(Piece &piece) {
    std::mt19937 eng = getGenerator();

    std::vector<Direction> directions = piece.getValidDirections();

    std::uniform_int_distribution<> directionRange(0, directions.size() - 1);
    std::uniform_real_distribution<float> movementRange(LOWER_RANDOM_MOVEMENT, UPPER_RANDOM_MOVEMENT);

    float move = movementRange(eng);
    Direction randomDir = directions[directionRange(eng)];

    piece.move(move, randomDir, BOARD_RADIUS, IS_BOUNDED_TO_BOARD);
}

/**
 * Method to delete pieces that are marked for deletion from the main game loop.
 * Also add 1 to the counter when a piece gets deleted. Uses RTTI to workout which counter should be incremented
 * Reverse for loop to shrink the vector
 */
void eraseAndCountPieces(std::vector<Piece *> &pieces) {
    int size = pieces.size();
    for (int i = size - 1; i >= 0; --i) {
        if (pieces[i]->toBeDeleted) {
            auto &t = *pieces[i];
            if (typeid(Rook) == typeid(t)) {
                rookCounter++;
            } else if (typeid(Bishop) == typeid(t)) {
                bishopCounter++;
            } else if (typeid(Queen) == typeid(t)) {
                queenCounter++;
            }
            delete pieces[i]; //Delete pointer before erasing
            pieces.erase(pieces.begin() + i);
        }
    }
}

int main() {
    // All pieces tracked in here
    std::vector<Piece *> pieces;
    initPieces(pieces);

    int rounds;
    for (rounds = 0; rounds < MAX_ROUNDS && pieces.size() > 1; ++rounds) {
        std::cout << std::endl << "Start of round " << rounds + 1 << std::endl;
        for (unsigned int i = 0; i < pieces.size(); ++i) {
            if (!pieces[i]->toBeDeleted) {
                //Move piece if its not supposed to be deleted
                moveRandomAmount(*pieces[i]);
                //check if this piece collides with any other piece
                for (unsigned int j = 0; j < pieces.size(); ++j) {
                    if (pieces[i]->isOverlapping(*pieces[j]) && i != j && !pieces[j]->toBeDeleted) {
                        pieces[j]->toBeDeleted = true;
                        std::cout << (*pieces[i]) << " Captured Piece " << (*pieces[j]) << std::endl;
                    }
                }
            }
        }
        eraseAndCountPieces(pieces);
        std::cout << "=====End of Round " << rounds + 1 << " with " << pieces.size() << " left on the board ====="
                  << std::endl;

    }

    std::cout << std::endl << "=============== Summary =============== " << std::endl
              << "Rook captured: " << rookCounter << std::endl
              << "Bishop captured: " << bishopCounter << std::endl
              << "Queen captured: " << queenCounter << std::endl
              << "Rounds: " << rounds << "/" << MAX_ROUNDS << std::endl
              << std::endl << "Remaining piece(s): " << std::endl;

    for (unsigned int i = 0; i < pieces.size(); ++i) {
        std::cout << (*pieces[i]) << std::endl;
    }

    float x;
    std::cin >> x;
    return 0;
}

