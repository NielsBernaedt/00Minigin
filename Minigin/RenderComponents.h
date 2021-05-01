#pragma once
#include <SDL_rect.h>
#include "BaseComponent.h"

class Font;
class Renderer;
struct SDL_Renderer;
class Texture2D;

class TextureRenderComponent : public BaseComponent
{
public:
	void Update(float deltaTime) override;
	void Render() const override;

	TextureRenderComponent(GameObject* gameObject, std::shared_ptr<Texture2D> texture, int x, int y, int width = 0, int height = 0);
	~TextureRenderComponent() override = default;
	TextureRenderComponent(const TextureRenderComponent& other) = delete;
	TextureRenderComponent(TextureRenderComponent&& other) = delete;
	TextureRenderComponent& operator=(const TextureRenderComponent& other) = delete;
	TextureRenderComponent& operator=(TextureRenderComponent&& other) = delete;

private:
	std::shared_ptr<Texture2D> m_Texture;
	SDL_Rect m_DstRect;
	//Transform m_Transform;
};

class TextRenderComponent : public BaseComponent
{
public:
	void Update(float deltaTime);
	void Render() const override;

	void SetText(const std::string& text);

	TextRenderComponent(GameObject* gameObject, std::shared_ptr<Font> font, const std::string& text, int x, int y, int width = 0, int height = 0);
	~TextRenderComponent() override = default;
	TextRenderComponent(const TextRenderComponent& other) = delete;
	TextRenderComponent(TextRenderComponent&& other) = delete;
	TextRenderComponent& operator=(const TextRenderComponent& other) = delete;
	TextRenderComponent& operator=(TextRenderComponent&& other) = delete;

private:
	std::shared_ptr<Font> m_Font;
	std::string m_Text;
	std::shared_ptr<Texture2D> m_Texture;
	bool m_NeedsUpdate;
	SDL_Rect m_DstRect;
	//Transform m_Transform;
};