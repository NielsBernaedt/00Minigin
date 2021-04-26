#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"

GameObject::~GameObject() = default;

void GameObject::Update(float deltaTime)
{
	for (auto &i : m_Components)
	{
		i->Update(deltaTime);
	}
}

void GameObject::Render() const
{
	const auto pos = m_Transform.GetPosition();
	if (m_Texture) //Because the FPS Counter object has no texture and it crashes
	{
		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}

	for(auto &i: m_Components)
	{
		i->Render();
	}
}

void GameObject::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	m_Components.push_back(component);
}
