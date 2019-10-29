#ifndef BOARD_H
#define BOARD_H

#include <map>

#include "Axial.h"

/*
 r  - - - - - - - - q                  r
    8 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 8
-8  . . . . . . . . . . . . C . . . . -8
                           /|
-7  . . . . . . . . . . . C-C . . . . -7
                         /|/|
-6  . . . . . . . . . . C-C-C . . . . -6
                       /|/|/|
-5  . . . . . . . . . C-C-C-C . . . . -5
                     /|/|/|/|
-4  . . . . G-G-G-G-o-o-o-o-o-B-B-B-B -4
            |/|/|/|/|/|/|/|/|/|/|/|/
-3  . . . . G-G-G-o-o-o-o-o-o-B-B-B . -3
            |/|/|/|/|/|/|/|/|/|/|/
-2  . . . . G-G-o-o-o-o-o-o-o-B-B . . -2
            |/|/|/|/|/|/|/|/|/|/
-1  . . . . G-o-o-o-o-o-o-o-o-B . . . -1
            |/|/|/|/|/|/|/|/|/
 0  . . . . o-o-o-o-O-o-o-o-o . . . .  0
           /|/|/|/|/|/|/|/|/|
 1  . . . R-o-o-o-o-o-o-o-o-P . . . .  1
         /|/|/|/|/|/|/|/|/|/|
 2  . . R-R-o-o-o-o-o-o-o-P-P . . . .  2
       /|/|/|/|/|/|/|/|/|/|/|
 3  . R-R-R-o-o-o-o-o-o-P-P-P . . . .  3
     /|/|/|/|/|/|/|/|/|/|/|/|
 4  R-R-R-R-o-o-o-o-o-P-P-P-P . . . .  4
            |/|/|/|/
 5  . . . . U-U-U-U . . . . . . . . .  5
            |/|/|/
 6  . . . . U-U-U . . . . . . . . . .  6
            |/|/
 7  . . . . U-U . . . . . . . . . . .  7
            |/
 8  . . . . U . . . . . . . . . . . .  8

    8 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 8
 r  - - - - - - - - q                  r
 */

#include <ostream>

#include "Axial.h"

class Board
{
    public:
        Board();
        void Display(std::ostream& os) const;
    private:
        void SetTopStart(char c);
        void SetUpperLeftStart(char c);
        void SetLowerLeftStart(char c);
        void SetBottomStart(char c);
        void SetLowerRightStart(char c);
        void SetUpperRightStart(char c);
        void SetCenter(char c);

        std::map<HexPoint, char> _state;
        const int m_home_width;
        const int m_radius; // center radius
};

#endif
