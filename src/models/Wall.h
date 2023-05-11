#pragma once
#include "../Interfaces/Helpers.h"
#include "../Interfaces/IObstacle.h"


namespace DLS
{
    class Wall : public IObstacle
    {
        private:
        const   EntityType  m_entityType        {EntityType::Obstacle};
        const   CellType    m_obstacleType      {CellType::Wall};
                Vector2D    m_position;
                Coordinate  m_coordinate;
        
        public:
        Vector2D PositionVector() const override { return m_position; }
        void SetPosition(Vector2D p) override {
            m_position = p;
        }
        EntityType Type() const override { return m_entityType; }

        void SetCoordinate(const Coordinate c) override { m_coordinate = c; }
        Coordinate GetCoordinate() const override { return m_coordinate; }
    };
}
