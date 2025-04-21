#pragma once

namespace DLSim
{
    using uint = unsigned int;

    enum class EntityType : uint
    {
        Wall = 1,
        Agent = 1000
    };

    /*
    Compass looks like t his:
    NW=6    N=7      NE=8
    W=3   CENTER=3   E=5
    SW=0    S=1      SE=2
    */
    enum class Compass : int
    {
        SW = 0,
        S,
        SE,
        W,
        CENTER,
        E,
        NW,
        N,
        NE
    };

    struct Coordinate
    {
        uint X;
        uint Y;

        Coordinate(unsigned int x, unsigned int y) : X(x), Y(y) {}
        Coordinate() : X(0), Y(0) {}

        bool IsValid() const
        {
            return X >= 0 && Y >= 0;
        }
    };

    struct Entity
    {
        unsigned int Id;
        EntityType Type;
    };
}
