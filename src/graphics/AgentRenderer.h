#pragma once
#include "../models/Agent.h"
#include "../Interfaces/Helpers.h"
#include <SFML/Graphics.hpp>

namespace DLS 
{
    class AgentRenderer : public Agent
    {
        private:
            sf::RenderWindow* m_context { nullptr };
            sf::CircleShape* m_shape {nullptr};
            sf::VertexArray m_forwardVector {sf::Lines, 2};
            sf::VertexArray m_sensors;

        void GetInputPlayer();
        void Draw();

        public:
        AgentRenderer(sf::RenderWindow* context, Vector2D startingPosition, float agentRadius, int id);
        virtual void Update() override;
    };
}
