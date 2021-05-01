#include "MiniginPCH.h"
#include "RenderComponents.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"

TextureRenderComponent::TextureRenderComponent(GameObject* gameObject, std::shared_ptr<Texture2D> texture, int x, int y, int width, int height)
	: BaseComponent( gameObject )
	, m_Texture{texture}
	, m_DstRect{x, y, width, height}
{
}

void TextureRenderComponent::Update(float)
{
}

void TextureRenderComponent::Render() const
{
	Renderer::GetInstance().RenderTexture(*m_Texture, float(m_DstRect.x), float(m_DstRect.y), float(m_DstRect.w), float(m_DstRect.h));
}

//////////////////////////////////////TEXTRENDERER//////////////////////////////////////

TextRenderComponent::TextRenderComponent(GameObject* gameObject, std::shared_ptr<Font> font, const std::string& text, int x, int y, int width, int height)
	: BaseComponent( gameObject )
	, m_Font{ font }
	, m_Text{ text }
	, m_Texture{ nullptr }
	, m_NeedsUpdate( true )
	, m_DstRect{ x, y, width, height }
{
}

void TextRenderComponent::Update(float)
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_Texture = std::make_shared<Texture2D>(texture);
		m_NeedsUpdate = false;
	}
}

void TextRenderComponent::Render() const
{
	if (m_Texture != nullptr)
	{
		Renderer::GetInstance().RenderTexture(*m_Texture, float(m_DstRect.x), float(m_DstRect.y));
	}
}

void TextRenderComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}