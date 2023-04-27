#pragma once
#include <IWorld.h>
#include <vector>
#include <set>

namespace DLS
{
    class World : public IWorld
    {
    private:
        std::set<int> m_activeAgents;
    protected:
        std::vector<CellInfo> m_worldCells;
        int m_sizeX;
        int m_sizeY;

        int GenerateRandomNumber(int mix, int max);

    public:
        virtual Coordinate AddAgentToWorld(IAgent* agent);
        virtual Vector2D GetCoordinateFromPosition(Coordinate c);
        virtual Coordinate GetWorldPositionFromCoordinate(Vector2D v);
        virtual CellInfo GetCellType(Coordinate c);
        virtual Coordinate GetCoordinateFromCellIndex(int index);
        virtual Coordinate GetWorldSize();
        virtual void SetSetType(Coordinate c, CellInfo info);
        virtual void SetWorldSize(Coordinate size);
        virtual void Update();
    };
}