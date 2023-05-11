#include "WallRenderer.h"

DLS::WallRenderer::WallRenderer(sf::RenderWindow* context, Vector2D position, Vector2D cellSize)
{
    SetPosition(position);
    m_context = context;

    m_shape = new sf::RectangleShape();
    SetPosition(position);
    m_shape->setFillColor(sf::Color::White);
    m_shape->setSize(sf::Vector2f(cellSize.x, cellSize.y));
    m_shape->setOrigin(sf::Vector2f(cellSize.x / 2, cellSize.y / 2));
    m_shape->setPosition(sf::Vector2f(position.x, position.y));
}

void DLS::WallRenderer::Update()
{
    m_context->draw(*m_shape);
}