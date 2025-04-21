#include "Renderer.hpp"

DLSim::Renderer::Renderer(const unsigned int screenSizeX, const unsigned int screenSizeY)
{
    m_context = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(screenSizeX, screenSizeY)), "Deep Learning Simulator");
    m_context->setFramerateLimit(60); // set the framerate
}

void DLSim::Renderer::Run()
{
    while (m_context->isOpen())
    {
        while (const std::optional event = m_context->pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
            m_context->close();
        }

        // clear the window with black color
        m_context->clear(sf::Color::Black);

        // draw everything here...
        sf::Font font;
        if (!font.openFromFile("/usr/share/fonts/TTF/DejaVuSans.ttf"))
        {
            throw std::runtime_error("Failed to load font");
        }
        sf::Text text(font); // a font is required to make a text object
        // set the string to display
        text.setString("Hello world");
        // set the character size
        text.setCharacterSize(24); // in pixels, not points!
        // set the color
        text.setFillColor(sf::Color::Red);
        // set the text style
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        m_context->draw(text);   


        // end the current frame
        m_context->display();
    }
}