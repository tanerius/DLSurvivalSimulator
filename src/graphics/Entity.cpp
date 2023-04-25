#include "Entity.h"
#include <cmath>

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

    auto pos = this->getPosition();
    this->setPosition(pos.x + m_reposition.x, pos.y + m_reposition.y);
    m_movementFLag = 0;
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