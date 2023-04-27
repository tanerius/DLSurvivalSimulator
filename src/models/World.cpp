#include "World.h"
#include <Helpers.h>
#include <vector>
#include <IAgent.h>

DLS::Coordinate DLS::World::AddAgentToWorld(DLS::IAgent* agent)
{
    int mod = m_sizeX * m_sizeY;
    int r = GenerateRandomNumber(0, mod);
    int count = 0;
    DLS::Coordinate newCoord;
    newCoord.X = -1;
    newCoord.Y = -1;
    while(m_activeAgents.find(r) != m_activeAgents.end())
    {
        r = (r+1) % mod;
        count++;
        if(count > mod)
            return newCoord;
    }
    m_activeAgents.insert(r);
    return GetCoordinateFromCellIndex(r);
}

DLS::Vector2D DLS::World::GetCenteredPositionFromCoordinate(DLS::Coordinate c)
{
    DLS::Vector2D ret;
    if(c.X >= m_sizeX || c.Y >= m_sizeY)
    {
        ret.x = -1;
        ret.y = -1;
    }

    ret.x = (m_cellSize.x / 2) * (c.X + 1);
    ret.y = (m_cellSize.y / 2) * (c.Y + 1);
    return ret;
}

DLS::Coordinate DLS::World::GetCoordinateFromPosition(DLS::Vector2D v)
{
    float minDistance = MAXFLOAT;
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

DLS::CellInfo DLS::World::GetCellType(Coordinate c)
{
    int index = c.X + c.Y*m_sizeX;
    return m_worldCells[index];
}

DLS::Coordinate DLS::World::GetCoordinateFromCellIndex(int index)
{
    return {index % m_sizeX, index / m_sizeX};
}