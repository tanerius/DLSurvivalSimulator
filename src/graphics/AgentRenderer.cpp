#include "AgentRenderer.h"
#include <cmath>

DLS::AgentRenderer::AgentRenderer(sf::RenderWindow* context, Vector2D startingPosition) :
    m_context(context),
    Agent(startingPosition)
{
    m_shape = new sf::CircleShape(20.0, 10);
    m_shape->setFillColor(sf::Color(100, 250, 50));
    m_shape->setPosition(sf::Vector2f(startingPosition.x, startingPosition.y));
    m_shape->setOrigin(sf::Vector2f(20.f, 20.f));
}

void DLS::AgentRenderer::GetInputPlayer()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        RotateRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Reverse();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        RotateLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Accelerate();
    }
}

bool DLS::AgentRenderer::HasCollided() 
{
    //TODO:implemenet
    return false;
}


void DLS::AgentRenderer::Update()
{
    Agent::Update();
    GetInputPlayer();
}

void DLS::AgentRenderer::Draw()
{
    auto newPos = GetPositionVector();
    auto rot = GetForwardVector();
    rot.x *= 50.0f;
    rot.y *= 50.0f;
    m_shape->setPosition(newPos.x, newPos.y);
    m_context->draw(*m_shape);

    // define the position of the triangle's points
    m_line[0].position = sf::Vector2f(newPos.x, newPos.y);
    m_line[1].position = sf::Vector2f(newPos.x + rot.x, newPos.y + rot.y);
    // define the color of the triangle's points
    m_line[0].color = sf::Color::Red;
    m_line[1].color = sf::Color::Red;
    m_context->draw(m_line);

}