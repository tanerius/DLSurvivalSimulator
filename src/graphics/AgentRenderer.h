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
            sf::VertexArray m_line {sf::Lines, 2};

        void GetInputPlayer();
        void Draw();

        public:
        AgentRenderer(sf::RenderWindow* context, Vector2D startingPosition);
        virtual bool HasCollided() override;
        virtual void Update() override;
    };
}
