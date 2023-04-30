#include <SFML/Graphics.hpp>
#include <AgentRenderer.h>
#include <WorldRenderer.h>

void DrawTestWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    window.setFramerateLimit(60); // set the framerate

    DLS::AgentRenderer shape(&window, {200,200});
    //DLS::WorldRenderer world({50, 50}, {30, 30}, &window);

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
        shape.Draw();


        // end the current frame
        window.display();
    }

}

int main()
{
    //DLS::WorldRenderer world({ 800,600 }, { 10,10 });
    //world.Run();
    DrawTestWindow();
    return 0;
}