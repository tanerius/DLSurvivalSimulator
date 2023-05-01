#include "AgentRenderer.h"
#include <cmath>

DLS::AgentRenderer::AgentRenderer(sf::RenderWindow* context, Vector2D startingPosition, float agentRadius) :
    m_context(context),
    Agent(startingPosition)
{
    m_shape = new sf::CircleShape(agentRadius / 2, 10);
    m_shape->setFillColor(sf::Color(100, 250, 50));
    m_shape->setPosition(sf::Vector2f(startingPosition.x, startingPosition.y));
    m_shape->setOrigin(sf::Vector2f(agentRadius / 2, agentRadius / 2));
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
    Draw();
}

void DLS::AgentRenderer::Draw()
{
    auto newPos = GetPositionVector();
    auto rot = GetForwardVector();
    auto getSensors = GetSensorVectors();
    rot.x *= 50.0f;
    rot.y *= 50.0f;
    m_shape->setPosition(newPos.x, newPos.y);
    m_context->draw(*m_shape);

    // Draw the forward vector
    m_forwardVector[0].position = sf::Vector2f(newPos.x, newPos.y);
    m_forwardVector[1].position = sf::Vector2f(newPos.x + rot.x, newPos.y + rot.y);
    // define the color of the forward vector
    m_forwardVector[0].color = sf::Color::Red;
    m_forwardVector[1].color = sf::Color::Red;
    m_context->draw(m_forwardVector);

    // Draw the sensors vectors
    m_sensors[0].position = sf::Vector2f(newPos.x, newPos.y);
    m_sensors[1].position = sf::Vector2f(getSensors[0].x, getSensors[0].y);
    m_sensors[2].position = sf::Vector2f(newPos.x, newPos.y);
    m_sensors[3].position = sf::Vector2f(getSensors[1].x, getSensors[1].y);
    m_sensors[4].position = sf::Vector2f(newPos.x, newPos.y);
    m_sensors[5].position = sf::Vector2f(getSensors[2].x, getSensors[2].y);

    m_sensors[0].color = sf::Color::Green;
    m_sensors[1].color = sf::Color::Green;
    m_sensors[2].color = sf::Color::Green;
    m_sensors[3].color = sf::Color::Green;
    m_sensors[4].color = sf::Color::Green;
    m_sensors[5].color = sf::Color::Green;
    m_context->draw(m_sensors);
}
