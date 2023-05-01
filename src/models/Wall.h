#pragma once
#include "../Interfaces/Helpers.h"
#include "../Interfaces/IObstacle.h"


namespace DLS
{
    class Wall : public IObstacle
    {
        private:
        const   EntityType  m_entityType        {EntityType::Obstacle};
                Vector2D    m_position;
        
        public:
        Vector2D PositionVector() const override { return m_position; }
        void SetPosition(Vector2D p) {
            m_position = p;
        }
        EntityType Type() const override { return m_entityType; }
    };
}
