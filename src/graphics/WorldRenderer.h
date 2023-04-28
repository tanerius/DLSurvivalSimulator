#pragma once
#include "../Interfaces/Helpers.h"
#include "../models/World.h"
#include <SFML/Graphics.hpp>

namespace DLS
{
    class WorldRenderer : public World
    {
        private:
            sf::RenderWindow* m_context { nullptr };
        public:
            WorldRenderer(Vector2D cellSize, Coordinate worldSize, sf::RenderWindow* context);
            virtual void Draw();
            virtual void Update();
    };
}