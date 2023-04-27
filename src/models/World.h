#pragma once
#include "Helpers.h"
#include <IWorld.h>
#include <vector>
#include <unordered_set>

namespace DLS
{
    class World : public IWorld
    {
    private:
        std::unordered_set<int> m_activeAgents;
        Vector2D m_cellSize;

        World() = delete;
    protected:
        std::vector<CellInfo> m_worldCells;
        int m_sizeX;
        int m_sizeY;

        int GenerateRandomNumber(int mix, int max);

    public:
        World(Vector2D cellSize, Coordinate worldSize);
        virtual Coordinate AddAgentToWorld(IAgent* agent);
        virtual Vector2D GetCenteredPositionFromCoordinate(Coordinate c);
        virtual Coordinate GetCoordinateFromPosition(Vector2D v);
        virtual CellInfo GetCellType(Coordinate c);
        virtual Coordinate GetCoordinateFromCellIndex(int index);
        virtual Coordinate GetWorldSize();
        virtual void SetCellType(Coordinate c, CellInfo info);
        virtual void SetWorldSize(Coordinate size);
        virtual void Update();
    };
}