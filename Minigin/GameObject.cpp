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

	for(auto &i: m_Components)
	{
		i->Render();
	}
}

void GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	m_Components.push_back(component);
}
