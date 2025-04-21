#pragma once

#include <vector>
#include "Types.hpp"

namespace DLSim
{
    const uint EMPTY = 0; // Index value 0 is reserved
    const uint BARRIER = 0xffff;

    class World
    {
    private:
        uint m_sizeX;
        uint m_sizeY;
        std::vector<uint> data;

    public:
        // Ctors
        World(const uint x, const uint y) : m_sizeX(x),
                                            m_sizeY(y),
                                            data{std::vector<uint>(x * y, EMPTY)} {
                                            };
        // Returning methods
        Coordinate GetRandomEmptyLocation() const;
        uint GetValueForCell(const Coordinate c) const;
        uint GetValueForCell(const uint x, const uint y) const
        {
            return GetValueForCell(Coordinate(x, y));
        }
        bool IsInBounds(const Coordinate c) const
        {
            return c.IsValid() && c.X < m_sizeX && c.Y < m_sizeY;
        }
        bool IsEmptyAt(const Coordinate c) const
        {
            return GetValueForCell(c) == EMPTY;
        }
        bool IsOccupiedAt(const Coordinate c) const
        {
            return GetValueForCell(c) != EMPTY;
        }
        uint SizeX() const
        {
            return m_sizeX;
        }
        uint SizeY() const
        {
            return m_sizeY;
        }

        // Non returning methods
        void EmptyFill();
        void Set(const Coordinate c, const uint value);
    };
}