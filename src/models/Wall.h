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
        
        void SetPosition(const Vector2D& p) override {
            m_position.x = p.x;
            m_position.y = p.y;
        }

        EntityType Type() const override { return m_entityType; }

        void SetCoordinate(const Coordinate& c) override 
        { 
            m_coordinate.X = c.X; 
            m_coordinate.Y = c.Y;
        }

        Coordinate GetCoordinate() const override { return m_coordinate; }

        virtual bool ComputeCollision() override { return false; }
    };
}
