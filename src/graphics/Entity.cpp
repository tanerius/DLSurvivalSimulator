#include "Entity.h"
#include <cmath>

DLS::Entity::Entity(sf::RenderWindow* context) :
    m_context(context),
    m_isAlive(true)
{
    m_shape.setFillColor(sf::Color(100, 250, 50));
}

void DLS::Entity::GetInputPlayer()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // left key is pressed: move our character
        GoE();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        // left key is pressed: move our character
        GoS();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // left key is pressed: move our character
        GoW();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        // left key is pressed: move our character
        GoN();
    }
}

void DLS::Entity::GoE()
{
    m_movementFLag = m_movementFLag | 4;
}

void DLS::Entity::GoN()
{
    m_movementFLag = m_movementFLag | 8;
}

void DLS::Entity::GoS()
{
    m_movementFLag = m_movementFLag | 2;
}

void DLS::Entity::GoW()
{
    m_movementFLag = m_movementFLag | 1;
}

bool DLS::Entity::HasCollided() 
{
    //TODO:implemenet
    return false;
}


void DLS::Entity::Update()
{
    GetInputPlayer();

    // North 
    if((m_movementFLag & 8) == 8)
        m_reposition.y -= m_accelleration;
    
    // South
    if((m_movementFLag & 2) == 2)
        m_reposition.y += m_accelleration;

    // East
    if((m_movementFLag & 4) == 4)
        m_reposition.x += m_accelleration;

    // West
    if((m_movementFLag & 1) == 1)
        m_reposition.x -= m_accelleration;

    ClampMaxSpeed();
    ApplyFriction();
    ApplyDriftCorrection();

    auto pos = m_shape.getPosition();
    m_shape.setPosition(pos.x + m_reposition.x, pos.y + m_reposition.y);
    m_movementFLag = 0;

    m_context->draw(m_shape);
}

void DLS::Entity::ClampMaxSpeed()
{
    if(m_reposition.y > m_maxSpeed)
        m_reposition.y = m_maxSpeed;
    if(m_reposition.y < -m_maxSpeed)
        m_reposition.y = -m_maxSpeed;
    if(m_reposition.x > m_maxSpeed)
        m_reposition.x = m_maxSpeed;
    if(m_reposition.x < -m_maxSpeed)
        m_reposition.x = -m_maxSpeed;
}

void DLS::Entity::ApplyFriction()
{
    if(m_reposition.y > 0)
        m_reposition.y -= m_friction;
    if(m_reposition.y < 0)
        m_reposition.y += m_friction;
    if(m_reposition.x > 0)
        m_reposition.x -= m_friction;
    if(m_reposition.x < 0)
        m_reposition.x += m_friction;
}

void DLS::Entity::ApplyDriftCorrection()
{
    if(std::abs(m_reposition.y) < m_friction)
        m_reposition.y = 0;
    if(std::abs(m_reposition.x) < m_friction)
        m_reposition.x = 0;
}