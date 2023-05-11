#pragma once
#include "../Interfaces/Helpers.h"
#include "../models/Wall.h"
#include <SFML/Graphics.hpp>

namespace DLS
{
    class WallRenderer : public Wall
    {
        private:
            sf::RenderWindow* m_context {nullptr};
            sf::RectangleShape* m_shape = nullptr;
            bool m_collided = false;
            
        public:
            WallRenderer(sf::RenderWindow* context, Vector2D position, Vector2D cellSize);
            inline sf::RenderWindow* GetContext() { return m_context; }
            bool HasCollided() const override { return false; }
            void SignalCollision() override { m_collided = true; }
            void Update() override;
    };
}
