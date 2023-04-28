#include "../Interfaces/Helpers.h"
#include "WorldRenderer.h"
#include <SFML/Graphics.hpp>
#include <algorithm>


void DLS::WorldRenderer::CreateTiles()
{
    //populate the tiles

    sf::RectangleShape* shape = nullptr;
    auto cellSize = GetCellSize();
    for (int i = 0; i < m_sizeX * m_sizeY; i++)
    {
        shape = new sf::RectangleShape();
        shape->setFillColor(sf::Color::Black);
        shape->setSize(sf::Vector2f(cellSize.x, cellSize.y));
        shape->setOrigin(sf::Vector2f(cellSize.x / 2, cellSize.y / 2));
        // set a 10-pixel wide orange outline
        shape->setOutlineThickness(1);
        shape->setOutlineColor(sf::Color(50, 50, 40));
        auto coord = GetCoordinateFromCellIndex(i);
        auto pos = GetCenteredPositionFromCoordinate(coord);
        shape->setPosition(sf::Vector2f(pos.x, pos.y));
        m_tiles.push_back(shape);
    }
}

DLS::WorldRenderer::WorldRenderer(DLS::Coordinate screenSize, DLS::Coordinate worldSize) :
    DLS::World(worldSize)
{
    
    m_context = new sf::RenderWindow(sf::VideoMode(screenSize.X, screenSize.Y), "Deep Learning Simulator");
    // Calculate how big an agent can be
    int maxSize = std::max(worldSize.X, worldSize.Y);
    float minWidth = std::min((float)screenSize.X, (float)screenSize.Y);
    minWidth = minWidth / maxSize;
    SetCellSize({ minWidth, minWidth });
    m_screenSize = screenSize;
    m_tiles.reserve(m_sizeX * m_sizeY);

    CreateTiles();
}

void DLS::WorldRenderer::Draw()
{
    // Draw the world
    for (auto tile : m_tiles)
    {
        m_context->draw(*tile);
    }
}

void DLS::WorldRenderer::Run()
{
    // run the program as long as the window is open
    while (m_context->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (m_context->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                m_context->close();
        }

        // clear the window with black color
        m_context->clear(sf::Color::Black);

        // draw everything here...
        Draw();

        // end the current frame
        m_context->display();
    }
}

DLS::Coordinate DLS::WorldRenderer::AddAgentToWorld(IAgent* agent)
{


    return {-1, -1};
}
