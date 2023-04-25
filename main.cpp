#include "src/graphics/Entity.h"
#include <SFML/Graphics.hpp>
#include <Entity.h>

void DrawTestWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
    window.setFramerateLimit(60); // set the framerate

    sf::CircleShape shape(50.f);

    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));

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
        auto pos = shape.getPosition();
        shape.setPosition(pos.x + 1.0, pos.y);

        window.draw(shape);


        // end the current frame
        window.display();
    }

}

int main()
{
    DLS::Entity e;
    e.Accelerate();
    DrawTestWindow();
    return 0;
}