#include "graphics/Renderer.hpp"

int main(void) 
{
    DLSim::Renderer simRenderer(800, 600);
    simRenderer.Run();
    
    return 0;
}