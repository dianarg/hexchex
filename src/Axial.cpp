#include "Axial.h"
#include <iostream>
CubePoint::CubePoint()
    : x(0), y(0), z(0)
{

}

CubePoint::CubePoint(int x, int y, int z)
    : x(x), y(y), z(z)
{
    if (x + y + z != 0) {
        throw std::runtime_error("Invalid coordinates for CubePoint");
    }
}

CubePoint::CubePoint(const HexPoint &hex)
    : x(hex.q), y(-hex.q - hex.r), z(hex.r)
{

}

std::set<CubePoint> CubePoint::Neighbors() const
{
    std::set<CubePoint> result;
    // upper left
    result.emplace(x, y+1, z-1);
    // upper right
    result.emplace(x+1, y, z-1);
    // left
    result.emplace(x-1, y+1, z);
    // right
    result.emplace(x+1, y-1, z);
    // lower left
    result.emplace(x-1, y, z+1);
    // lower right
    result.emplace(x, y-1, z+1);
    return result;
}

std::string CubePoint::ToString() const
{
    std::string str = "(";
    str += std::to_string(x) + ", ";
    str += std::to_string(y) + ", ";
    str += std::to_string(z) + ")";
    return str;
}

bool CubePoint::operator==(const CubePoint &other) const
{
    return ((this->x == other.x) && (this->y == other.y) && (this->z == other.z));
}

bool CubePoint::operator<(const CubePoint &other) const
{
    return ((this->x < other.x) ||
            (this->x == other.x && this->y < other.y) ||
            (this->x == other.x && this->y == other.y && this->z < other.z));
}

std::ostream& operator<<(std::ostream& os, const CubePoint &cube)
{
    os << cube.ToString();
    return os;
}

HexPoint::HexPoint()
    : q(0), r(0)
{

}

HexPoint::HexPoint(int q, int r)
    : q(q), r(r)
{

}

HexPoint::HexPoint(const CubePoint &cube)
    : q(cube.x), r(cube.z)
{

}

bool HexPoint::operator==(const HexPoint &other) const
{
    return (this->q == other.q && this->r == other.r);
}

bool HexPoint::operator<(const HexPoint &other) const
{
    return (CubePoint(*this) < CubePoint(other));
}
