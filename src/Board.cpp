#include "Board.h"

#include <iostream> // for DisplayBoard

Board::Board()
{
    int r = -8;
    // top center
    int bq = 4;
    int eq = 4;
    for (int row = 0; row < 4; ++row) {
        for (bq = eq - row; bq<=eq; bq++) {
            state[{bq, r}] = 'C';
        }
        ++r;
    }
    // TODO: split left and right into different players, use o for center
    // top left and right
    for (int row = 0; row < 4; ++row) {
        bq = -4;
        for (eq = 8-row; bq <= eq; ++bq) {
            state[{bq, r}] = 'G';
        }
        ++r;
    }
    // center
    bq = -4;
    eq = 4;
    for (; bq <= eq; ++bq) {
        state[{bq, r}] = 'o';
    }
    ++r;

    // bottom left and right
    for (int row = 0; row < 4; ++row) {
        eq = 4;
        for (bq = eq - row - 8; bq <= eq; ++bq) {
            state[{bq, r}] = 'R';
        }
        ++r;
    }

    // bottom center
    for (int row = 0; row < 4; ++row) {
        bq = -4;
        for (eq = 0-row-1; bq <= eq; ++bq) {
            state[{bq, r}] = 'U';
        }
        ++r;
    }
}


void DisplayBoard(const Board &board)
{
    // print q axis
    std::cout << "   ";
    for (int q = -8; q <= 8; ++q) {
        std::cout << (q < 0 ? -q : q) << " ";
    }
    std::cout << std::endl;
    int r = -8;
    for (int row = 0; row <= 17; ++row) {
        if (r>=0) {
            std::cout << " ";
        }
        std::cout << r << " ";

        int q = -8;
        for (int col = 0; col <= 17; ++col) {
            auto cell = board.state.find({q,r});
            if (cell != board.state.end()) {
                std::cout << cell->second << " ";
            }
            else {
                std::cout << ". ";
            }
            ++q;
        }
        std::cout << std::endl;
        ++r;
    }

}
