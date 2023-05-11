#pragma once
#include <Helpers.h>
#include <IWorld.h>
#include <vector>
#include <unordered_set>
#include <random>

namespace DLS
{
    class World : public IWorld
    {
    private:
        Vector2D m_cellSize;
        std::random_device m_rd;

        World() = delete;
    protected:
        std::vector<IEntity*> m_activeEntities;
        std::vector<CellInfo> m_worldCells;
        int m_sizeX;
        int m_sizeY;

        int GenerateRandomNumber(int min, int max);
        void SetCellSize(Vector2D size);

    public:
        World(Coordinate worldSize);
        Vector2D GetCellSize() const;
        void AddEntityToWorld(IEntity* entity) override; 
        Vector2D GetCenteredPositionFromCoordinate(Coordinate c) override;
        Coordinate GetCoordinateFromPosition(Vector2D v) override;
        int GetIndexFromCoordinate(Coordinate coordinate) override;
        CellInfo GetCellInfo(Coordinate c) override;
        Coordinate GetCoordinateFromCellIndex(int index) override;
        Coordinate GetWorldSize() override;
        void SetCellType(Coordinate c, CellInfo info) override;
        void SetWorldSize(Coordinate size) override;
        virtual void Draw() override = 0; // pure virtual here because any inherritor class should implement this
    };
}