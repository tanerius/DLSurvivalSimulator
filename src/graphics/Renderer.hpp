#pragma once
#include <SFML/Graphics.hpp>

namespace DLSim {
    class Renderer
    {
        private:
            sf::RenderWindow* m_context {nullptr};
            sf::RectangleShape* m_shape = nullptr;

        public:
        Renderer(const unsigned int screenSizeX, const unsigned int screenSizeY);
            void Run();
    };
}