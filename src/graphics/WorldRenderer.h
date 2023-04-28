#pragma once
#include "../Interfaces/Helpers.h"
#include "../models/World.h"
#include <SFML/Graphics.hpp>

namespace DLS
{
    class WorldRenderer : public World
    {
        private:
            Coordinate m_screenSize;
            sf::RenderWindow* m_context = nullptr;
            std::vector<sf::RectangleShape*> m_tiles;

            void CreateTiles();

        public:
            WorldRenderer(Coordinate screenSize, Coordinate worldSize);
            virtual void Draw();
            void Run();
            virtual Coordinate AddAgentToWorld(IAgent* agent);
    };
}