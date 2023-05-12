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
            bool m_printed = false;
            sf::Font m_font;

        public:
            WorldRenderer(Coordinate screenSize, Coordinate worldSize);

            inline sf::RenderWindow* GetContext() { return m_context; }
            virtual void Draw();
            void Run();
    };
}