#include "WallRenderer.h"
#include <SFML/Graphics.hpp>
#include <AgentRenderer.h>
#include <WorldRenderer.h>
#include <Sensor.h>
#include <iostream>

void DrawTestWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    window.setFramerateLimit(60); // set the framerate

    DLS::AgentRenderer shape(&window, {200, 200}, 20.f);
    // DLS::WorldRenderer world({50, 50}, {30, 30}, &window);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        shape.Update();

        // end the current frame
        window.display();
    }
}

DLS::AgentRenderer* CreateAgent(DLS::WorldRenderer& currentWorld,  DLS::Coordinate where)
{
    auto agentPos = currentWorld.GetCenteredPositionFromCoordinate(where);
    auto cellSize = currentWorld.GetCellSize();
    float agentSize = std::min(cellSize.x, cellSize.y);

    agentSize = agentSize * 0.7f;

    return new DLS::AgentRenderer(currentWorld.GetContext(), agentPos, agentSize);
}

DLS::WallRenderer* CreateWall(DLS::WorldRenderer& currentWorld,  DLS::Coordinate where)
{
    auto agentPos = currentWorld.GetCenteredPositionFromCoordinate(where);
    auto cellSize = currentWorld.GetCellSize();

    cellSize.x = cellSize.x * 0.9f;
    cellSize.y = cellSize.y * 0.9f;

    return new DLS::WallRenderer(currentWorld.GetContext(), agentPos, cellSize);
}

int main(void)
{
    DLS::Sensor* s = nullptr;
    DLS::WorldRenderer world({ 1000, 1000 }, { 50, 50 });
    
    auto agent = CreateAgent(world, {3,3});
    world.AddEntityToWorld(agent);

    for (int i = 0; i < 10 ; i++)
    {
        auto w = CreateWall(world, {0,i});
        world.AddEntityToWorld(w);
    }

    world.Run();

    delete agent;

    return 0;
}