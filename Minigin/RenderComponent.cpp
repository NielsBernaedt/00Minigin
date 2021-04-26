#include "MiniginPCH.h"
#include "RenderComponent.h"
#include <SDL.h>
#include "Renderer.h"

RenderComponent::RenderComponent(Renderer* renderer, std::shared_ptr<Texture2D> texture, int x, int y, int width, int height)
	: m_Renderer { renderer }
	, m_Texture {texture}
	, m_DstRect{x, y, width, height}
{
}

void RenderComponent::Update(float)
{
}

void RenderComponent::Render() const
{
	m_Renderer->RenderTexture(*m_Texture, float(m_DstRect.x), float(m_DstRect.y), float(m_DstRect.w), float(m_DstRect.h));
}