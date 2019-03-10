#ifndef AXIAL_H
#define AXIAL_H

#include <set>
#include <string>
#include <ostream>

class CubePoint;
class HexPoint;

class CubePoint
{
        friend class HexPoint;
    public:
        CubePoint();
        CubePoint(int x, int y, int z);
        CubePoint(const HexPoint &hex);
        ~CubePoint() = default;
        std::set<CubePoint> Neighbors() const;
        std::string ToString() const;
        bool operator==(const CubePoint &other) const;
        bool operator<(const CubePoint &other) const;
    private:
        int x;
        int y;
        int z;
};

std::ostream& operator<<(std::ostream& os, const CubePoint &cube);

class HexPoint
{
        friend class CubePoint;
    public:
        HexPoint();
        HexPoint(int q, int r);
        HexPoint(const CubePoint &cube);
        ~HexPoint() = default;
        bool operator==(const HexPoint &other) const;
        bool operator<(const HexPoint &other) const;
    private:
        int q;
        int r;
};


#endif
