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
            
        public:
            WallRenderer(sf::RenderWindow* context, Vector2D position);
            inline sf::RenderWindow* GetContext() { return m_context; }
            bool HasCollided() override { return false; }
            void Update() override;
    };
}
