#include "Board.h"

#include <iostream>

Board::Board()
    : m_home_width(4)
    , m_radius(4)
{
    // Players 1-6, numbered from top counterclockwise
    SetTopStart('1');
    SetUpperLeftStart('2');
    SetLowerLeftStart('3');
    SetBottomStart('4');
    SetLowerRightStart('5');
    SetUpperRightStart('6');

    // board center
    SetCenter('.');
}

void Board::SetTopStart(char c)
{
    // start at radius below center and move down, decreasing width of layer at each step
    int width = m_home_width;
    for (int z = -(m_radius+1); z >= -(2*m_radius); --z) {
        for (int x = m_home_width - width + 1; x <= m_home_width; ++x) {
            CubePoint cube {x, -x-z, z};
            std::cout << cube << std::endl;
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetUpperLeftStart(char c)
{
    // start at radius below center and move down, decreasing width of layer at each step
    int width = m_home_width;
    for (int y = m_radius+1; y <= 2*m_radius; ++y) {
        for (int x = -m_home_width; x <= -m_home_width + width -1; ++x) {
            CubePoint cube {x, y, -x-y};
            std::cout << cube << std::endl;
            _state[cube] = c;
        }
        --width;
    }

}

void Board::SetLowerLeftStart(char c)
{
    // start at radius below center and move down, decreasing width of layer at each step
    int width = m_home_width;
    for (int x = -(m_radius+1); x >= -(2*m_radius); --x) {
        for (int y = m_home_width - width + 1; y <= m_home_width; ++y) {
            CubePoint cube {x, y, -x-y};
            std::cout << cube << std::endl;
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetBottomStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = m_home_width;
    for (int z = m_radius+1; z <= 2*m_radius; ++z) {
        for (int x = -m_home_width; x <= -m_home_width + width -1; ++x) {
            CubePoint cube {x, -x-z, z};
            std::cout << cube << std::endl;
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetLowerRightStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = m_home_width;
    for (int y = -(m_radius+1); y >= -(2*m_radius); --y) {
        for (int x = m_home_width - width + 1; x <= m_home_width; ++x) {
            CubePoint cube {x, y, -x-y};
            std::cout << cube << std::endl;
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetUpperRightStart(char c)
{
    // start at radius from center and move out, decreasing width of layer at each step
    int width = m_home_width;
    for (int x = m_radius+1; x <= 2*m_radius; ++x) {
        for (int y = -m_home_width; y <= -m_home_width + width -1; ++y) {
            CubePoint cube {x, y, -x-y};
            std::cout << cube << std::endl;
            _state[cube] = c;
        }
        --width;
    }
}

void Board::SetCenter(char c)
{
    CubePoint center {0, 0, 0};
    // fill in all cells at dist from center, converting from cube to hex
    for (int x = -m_radius; x <= m_radius; ++x) {
        for (int y = std::max(-m_radius, -x-m_radius); y <= std::min(m_radius, -x+m_radius); ++y) {
            // cube constraint: x+y+z=0
            int z = -x-y;
            CubePoint cube {x, y, z};
            _state[cube] = c;
        }
    }
}

void Board::Display(std::ostream& os) const
{
    char background = '_';
    // print q axis
    os << "   ";
    for (int q = -m_radius -m_home_width; q <= m_radius + m_home_width; ++q) {
        os << (q < 0 ? -q : q) << " ";
    }
    os << std::endl;
    int r = -8;
    for (int row = 0; row <= 2*m_radius + 2*m_home_width; ++row) {
        if (r>=0) {
            os << " ";
        }
        // print r labels
        os << r << " ";

        int q = -8;
        // print filled or empty cells
        for (int col = 0; col <= 2*m_radius + 2*m_home_width; ++col) {
            auto cell = _state.find({q,r});
            if (cell != _state.end()) {
                os << cell->second << " ";
            }
            else {
                os << background << " ";
            }
            ++q;
        }
        os << std::endl;
        ++r;
    }
}
