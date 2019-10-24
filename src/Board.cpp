#include "Board.h"

#include <iostream>

Board::Board()
{
    // Players 1-6, numbered from top counterclockwise

    // player 1
    SetTopStart('1');

    // player 2
    // SetUpperLeftStart('2');

    // // player 3
    // SetLowerLeftStart('3');

    // // player 4
    // SetBottomStart('4');

    // // player 5
    // SetLowerRightStart('5');

    // // player 6
    // SetUpperRightStart('6');

    // // board center
    // SetCenter('o');
}

void Board::SetTopStart(char c)
{
    // int width = 4;
    // for (int r = -5; r >= -8; --r) {
    //     for (int q = 4 - width + 1; q <= 4 ; ++q) {
    //         _state[{q, r}] = c;
    //     }
    //     --width;
    // }

    int width = 3; //width of home base
    int rad = 3;  // center radius
    // start at rad above center and move up, decreasing width of layer at each step
    int y = width;
    for (int z = -(rad+1); z >= -(2*rad); --z) {
        for (int x = -y-z; x <= width; ++x) {
            y = -x-z;
            std::cout << x << " " << y << " " << z << std::endl;
            CubePoint cube {x, y, z};
            std::cout << cube << std::endl;
            _state[cube] = 'a' + z;
        }
        --width;
    }
}

void Board::SetUpperLeftStart(char c)
{
    int width = 4;
    for (int r = -4; r <= 0; ++r) {
        for (int q = -4; q < -4+width; ++q) {
            _state[{q, r}] = c;
        }
        --width;
    }
}

void Board::SetLowerLeftStart(char c)
{
    int width = 1;
    for (int r = 1; r <= 4; ++r) {
        for (int q = -5; q >= -4 - width; --q) {
            _state[{q, r}] = '3';
        }
        ++width;
    }
}

void Board::SetBottomStart(char c)
{
    int width = 4;
    for (int r = 5; r <= 8; ++r) {
        for (int q = -4; q < -4 + width; ++q) {
            _state[{q, r}] = '4';
        }
        --width;
    }
}

void Board::SetLowerRightStart(char c)
{
    int width = 1;
    for (int r = 0; r <= 4; ++r) {
        for (int q = 4; q > 4 - width + 1; --q) {
            _state[{q, r}] = '5';
        }
        ++width;
    }
}

void Board::SetUpperRightStart(char c)
{
    int width = 4;
    for (int r = -4; r <= -1; ++r) {
        for (int q = 5; q < 5 + width; ++q) {
            _state[{q, r}] = '6';
        }
        --width;
    }
}

void Board::SetCenter(char c)
{
    CubePoint center {0, 0, 0};
    // fill in all cells at dist from center, converting from cube to hex
    int dist = 4;
    for (int x = -dist; x <= dist; ++x) {
        for (int y = std::max(-dist, -x-dist); y <= std::min(dist, -x+dist); ++y) {
            // cube constraint: x+y+z=0
            int z = -x-y;
            CubePoint cube {x, y, z};
            _state[cube] = 'o';
        }
    }
}

void Board::Display(std::ostream& os) const
{
    // print q axis
    os << "   ";
    for (int q = -8; q <= 8; ++q) {
        os << (q < 0 ? -q : q) << " ";
    }
    os << std::endl;
    int r = -8;
    for (int row = 0; row <= 17; ++row) {
        if (r>=0) {
            os << " ";
        }
        // print r labels
        os << r << " ";

        int q = -8;
        // print filled or empty cells
        for (int col = 0; col <= 17; ++col) {
            auto cell = _state.find({q,r});
            if (cell != _state.end()) {
                os << cell->second << " ";
            }
            else {
                os << ". ";
            }
            ++q;
        }
        os << std::endl;
        ++r;
    }
}
