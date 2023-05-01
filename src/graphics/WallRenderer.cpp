#include "WallRenderer.h"

DLS::WallRenderer::WallRenderer(sf::RenderWindow* context, Vector2D position)
{
    SetPosition(position);
    m_context = context;
}

void DLS::WallRenderer::Update()
{
    
}