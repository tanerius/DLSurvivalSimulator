#pragma once
#include "../Interfaces/IAgent.h"
#include "Helpers.h"
#include <SFML/Graphics.hpp>

namespace DLS 
{
    class Entity : public IAgent, public sf::CircleShape
    {
        private:
        const   float       m_maxSpeed  {4.0};
        const   float       m_friction  {0.15};
                bool        m_isAlive   {true};
                Vector2D    m_reposition{0, 0};

        /// @brief 4 bit bitfield NESW
        int m_movementFLag = 0;
        float m_accelleration = 0.5;

        /// @brief Clamp speed to max speed
        void ClampMaxSpeed();
        /// @brief basic friction computation
        void ApplyFriction();
        /// @brief prevent drifting
        void ApplyDriftCorrection();


        public:
        Entity() :
          m_isAlive(true),
          sf::CircleShape(20.0, 10)
           { 
             
           }

        float MaxSpeed() const { return m_maxSpeed; }

        virtual void GoN() override;
        virtual void GoE() override;
        virtual void GoS() override;
        virtual void GoW() override;
        virtual bool IsAlive() override { return m_isAlive; };
        virtual bool HasCollided() override;
        virtual void Update() override;
    };
}
