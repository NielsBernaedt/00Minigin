#pragma once
#include <SDL_rect.h>
#include "BaseComponent.h"

class Renderer;
struct SDL_Renderer;
class Texture2D;

class RenderComponent : public BaseComponent
{
public:
	void Update(float deltaTime) override;
	void Render() const override;

	RenderComponent(Renderer* renderer, std::shared_ptr<Texture2D> texture, int x, int y, int width = 0, int height = 0);
	~RenderComponent() override = default;
	RenderComponent(const RenderComponent& other) = delete;
	RenderComponent(RenderComponent&& other) = delete;
	RenderComponent& operator=(const RenderComponent& other) = delete;
	RenderComponent& operator=(RenderComponent&& other) = delete;

private:
	Renderer* m_Renderer;
	std::shared_ptr<Texture2D> m_Texture;
	SDL_Rect m_DstRect;
};
