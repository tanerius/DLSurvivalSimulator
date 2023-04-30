#include "AgentRenderer.h"
#include <cmath>

DLS::AgentRenderer::AgentRenderer(sf::RenderWindow* context, Vector2D startingPosition) :
    m_context(context),
    Agent(startingPosition)
{
    m_shape = new sf::CircleShape(20.0, 10);
    m_shape->setFillColor(sf::Color(100, 250, 50));
    m_shape->setPosition(sf::Vector2f(startingPosition.x, startingPosition.y));
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
    GetInputPlayer();
    Agent::Update();
}

void DLS::AgentRenderer::Draw()
{
    auto newPos = GetPositionVector();
    m_shape->setPosition(newPos.x, newPos.y);
    m_context->draw(*m_shape);
}