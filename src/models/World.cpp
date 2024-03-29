#include "World.h"
#include "Agent.h"
#include <Helpers.h>
#include <vector>
#include <IAgent.h>
#include <limits>

DLS::World::World(Coordinate worldSize) : m_cellSize({10, 10})
{
    m_sizeX = worldSize.X; 
    m_sizeY = worldSize.Y;
    m_worldCells.resize(m_sizeX * m_sizeY, {DLS::CellType::Flat, 0, 0});
    m_activeEntities.clear();
}

void DLS::World::AddEntityToWorld(DLS::IEntity* entity)
{
    m_activeEntities.insert(entity);
    entity->AddToWorld(this);
}

void DLS::World::RemoveEntityFromWorld(IEntity* e)
{
    m_activeEntities.erase(e);
    e->RemoveFromWorld();
}

DLS::Vector2D DLS::World::GetCenteredPositionFromCoordinate(const DLS::Coordinate& c) const
{
    DLS::Vector2D ret;
    if(c.X >= m_sizeX || c.Y >= m_sizeY)
    {
        ret.x = -1;
        ret.y = -1;
    }

    ret.x = m_cellSize.x * c.X + m_cellSize.x / 2;
    ret.y = m_cellSize.y * c.Y + m_cellSize.y / 2;
    return ret;
}

DLS::Coordinate DLS::World::GetCoordinateFromPosition(const DLS::Vector2D& v) const
{
    float minDistance = std::numeric_limits<float>::max();
    DLS::Coordinate ret = {-1, -1};
    
    for(int x0 = 0; x0 < m_sizeX; x0++)
    {
        for(int y0 = 0; y0 < m_sizeY; y0++)
        {
            DLS::Vector2D tmp = GetCenteredPositionFromCoordinate({x0, y0});
            float d = DLS::Vector2D::Distance(v, tmp);
            if(d < minDistance)
            {
                minDistance = d;
                ret.X = x0;
                ret.Y = y0;
            }
        }
    }
    return ret;
}

DLS::CellInfo DLS::World::GetCellInfo(const Coordinate& c) const
{
    int index = c.X + c.Y*m_sizeX;
    return m_worldCells[index];
}

DLS::Coordinate DLS::World::GetCoordinateFromCellIndex(const int index) const
{
    return {index % m_sizeX, index / m_sizeX};
}

int DLS::World::GetIndexFromCoordinate(const DLS::Coordinate& c) const
{
    return c.X + c.Y*m_sizeX;
}

DLS::Coordinate DLS::World::GetWorldSize() const
{
    return {m_sizeX, m_sizeY};
}

void DLS::World::SetCellInfo(const Coordinate& c, const CellInfo& info)
{
    int index = GetIndexFromCoordinate(c);
    m_worldCells[index] = info;
}

void DLS::World::SetWorldSize(const Coordinate& size)
{
    m_sizeX = size.X;
    m_sizeY = size.Y;
}

void DLS::World::Draw()
{
    // draw
}

int DLS::World::GenerateRandomNumber(int min, int max)
{
    std::mt19937 gen(m_rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(min, max);
 
    return distrib(gen);
}

void DLS::World::SetCellSize(Vector2D size)
{
    m_cellSize = size;
}

DLS::Vector2D DLS::World::GetCellSize() const 
{
    return m_cellSize;
}
