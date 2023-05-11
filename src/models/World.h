#pragma once
#include <Helpers.h>
#include <IWorld.h>
#include <vector>
#include <unordered_set>
#include <random>
#include <unordered_set>

namespace DLS
{
    class World : public IWorld
    {
    private:
        Vector2D m_cellSize;
        std::random_device m_rd;

        World() = delete;
    protected:
        std::unordered_set<IEntity*> m_activeEntities;
        std::vector<CellInfo> m_worldCells;
        int m_sizeX;
        int m_sizeY;

        int GenerateRandomNumber(int min, int max);
        void SetCellSize(Vector2D size);

    public:
        World(Coordinate worldSize);
        virtual Vector2D GetCellSize() const override; // can be overriden if necessary
        void AddEntityToWorld(IEntity* entity) override; 
        void RemoveEntityFromWorld(IEntity* e) override;
        Vector2D GetCenteredPositionFromCoordinate(const Coordinate& c) const override;
        Coordinate GetCoordinateFromPosition(const Vector2D& v) const override;
        int GetIndexFromCoordinate(const Coordinate& coordinate) const override;
        CellInfo GetCellInfo(const Coordinate& c) const override;
        Coordinate GetCoordinateFromCellIndex(const int index) const override;
        Coordinate GetWorldSize() const override;
        void SetCellType(const Coordinate& c, const CellInfo& info) override;
        void SetWorldSize(const Coordinate& size) override;

        virtual void Draw() override = 0; // pure virtual here because any inherritor class should implement this
    };
}