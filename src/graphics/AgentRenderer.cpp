#include "AgentRenderer.h"
#include <cmath>

DLS::AgentRenderer::AgentRenderer(sf::RenderWindow* context, Vector2D startingPosition, float agentRadius, int id, bool ai) :
    m_context(context),
    m_isAI(ai),
    Agent(startingPosition, id)
{
    SetHeightWidth({agentRadius,agentRadius});
    m_shape = new sf::CircleShape(agentRadius / 2, 10);
    m_shape->setFillColor(sf::Color(100, 250, 50));
    m_shape->setPosition(sf::Vector2f(startingPosition.x, startingPosition.y));
    m_shape->setOrigin(sf::Vector2f(agentRadius / 2, agentRadius / 2));

    m_sensors.clear();
    m_sensors.setPrimitiveType(sf::PrimitiveType::Lines);
    m_sensors.resize(GetSensorRayCount()*2);
}

void DLS::AgentRenderer::GetInputPlayer()
{
    if (!m_isAI)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            RotateRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            Reverse();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            RotateLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            Accelerate();
        }
    }
    else
    {
        // TODO: AI Controlled movement here
    }
}

void DLS::AgentRenderer::Update()
{
    Agent::Update();
    //if (!HasCollided())
    {
        GetInputPlayer();
        ComputeCollision();
    }
    Draw();
}

void DLS::AgentRenderer::Draw()
{
    auto newPos = PositionVector();
    auto rot = GetForwardVector();
    auto getSensors = GetSensorVectors();
    rot.x *= 50.0f;
    rot.y *= 50.0f;
    m_shape->setPosition(sf::Vector2f(newPos.x, newPos.y));
    
    if (HasCollided())
    {
        m_shape->setFillColor(sf::Color(250, 50, 50));
    }
    else
    {
        if(!m_isAI)
            m_shape->setFillColor(sf::Color(100, 250, 50));
        else
            m_shape->setFillColor(sf::Color(50, 100, 250));
    }

    m_context->draw(*m_shape);

    // Draw the forward vector
    m_forwardVector[0].position = sf::Vector2f(newPos.x, newPos.y);
    m_forwardVector[1].position = sf::Vector2f(newPos.x + rot.x, newPos.y + rot.y);
    // define the color of the forward vector
    m_forwardVector[0].color = sf::Color::Red;
    m_forwardVector[1].color = sf::Color::Red;
    m_context->draw(m_forwardVector);

    // Draw the sensors vectors
    int rayCount = GetSensorRayCount();
    for (int i = 0; i < rayCount; i++)
    {
        int j = 2 * i;
        m_sensors[j].position = sf::Vector2f(newPos.x, newPos.y);
        m_sensors[j+1].position = sf::Vector2f(getSensors[i].x, getSensors[i].y);
        if (!m_isAI)
        {
            m_sensors[j].color = sf::Color::Green;
            m_sensors[j + 1].color = sf::Color::Green;
        }
        else
        {
            m_sensors[j].color = sf::Color::Blue;
            m_sensors[j + 1].color = sf::Color::Blue;
        }
    }
    m_context->draw(m_sensors);
}
