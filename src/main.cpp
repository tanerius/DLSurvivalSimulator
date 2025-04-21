#include "graphics/Renderer.hpp"
#include "Agent.hpp"

int main(void)
{
    DLSim::Renderer simRenderer(800, 600);
    simRenderer.Run();

    return 0;
}