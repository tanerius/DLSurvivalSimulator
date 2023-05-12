#include "WallRenderer.h"
#include <SFML/Graphics.hpp>
#include <AgentRenderer.h>
#include <WorldRenderer.h>
#include <Sensor.h>
#include <iostream>

int id = 1;
int agentid = 10000;

DLS::AgentRenderer* CreateAgent(DLS::WorldRenderer& currentWorld,  DLS::Coordinate where)
{
    auto agentPos = currentWorld.GetCenteredPositionFromCoordinate(where);
    auto cellSize = currentWorld.GetCellSize();
    float agentSize = std::min(cellSize.x, cellSize.y);

    agentSize = agentSize * 0.7f;

    return new DLS::AgentRenderer(currentWorld.GetContext(), agentPos, agentSize, agentid++);
}

DLS::WallRenderer* CreateWall(DLS::WorldRenderer& currentWorld,  DLS::Coordinate where)
{
    auto agentPos = currentWorld.GetCenteredPositionFromCoordinate(where);
    auto cellSize = currentWorld.GetCellSize();

    cellSize.x = cellSize.x * 0.9f;
    cellSize.y = cellSize.y * 0.9f;

    return new DLS::WallRenderer(currentWorld.GetContext(), agentPos, cellSize, id++);
}

int main(void)
{
    DLS::Sensor* s = nullptr;
    DLS::WorldRenderer world({ 1000, 1000 }, { 50, 50 });
    
    auto agent = CreateAgent(world, {3,3});
    world.AddEntityToWorld(agent);
    auto size = world.GetWorldSize();

    /*
    for (int x = 0; x < size.X; x++)
    {
        auto w = CreateWall(world, { x, 0 });
        world.AddEntityToWorld(w);
        w = CreateWall(world, { x, size.Y-1 });
        world.AddEntityToWorld(w);
    }

    for (int y = 0; y < size.Y; y++)
    {
        auto w = CreateWall(world, { 0, y });
        world.AddEntityToWorld(w);
        w = CreateWall(world, { size.X - 1, y });
        world.AddEntityToWorld(w);
    }
    */
    auto w = CreateWall(world, { 20, 20 });
    world.AddEntityToWorld(w);

    world.Run();

    delete agent;

    return 0;
}