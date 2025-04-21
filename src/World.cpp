#include "World.hpp"
#include "Random.hpp"
#include <cassert>

DLSim::uint DLSim::World::GetValueForCell(const Coordinate c) const
{
    if (!IsInBounds(c))
        return BARRIER;

    return data[c.X + c.Y * m_sizeX];
}

void DLSim::World::EmptyFill()
{
    std::fill(data.begin(), data.end(), EMPTY);
}

DLSim::Coordinate DLSim::World::GetRandomEmptyLocation() const
{
    Coordinate c(0, 0);
    do
    {
        c.X = DLSim::randomUInt(0, m_sizeX - 1);
        c.Y = DLSim::randomUInt(0, m_sizeY - 1);
    } while (!IsEmptyAt(c));

    return c;
}

void DLSim::World::Set(const DLSim::Coordinate c, const DLSim::uint value)
{
    assert(IsInBounds(c) && "Corrdinate not in bounds");
    data[c.X + c.Y * m_sizeX] = value;
}