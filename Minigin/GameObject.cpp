#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"

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
	const auto pos = m_Position;

	for(auto &i: m_Components)
	{
		i->Render();
	}
}

void GameObject::SetPosition()
{
	for (size_t i{}; i < this->GetAllComponents().size(); ++i)
	{
		if (typeid(this->GetAllComponents()[i]) == typeid(TransformComponent))
		{
			BaseComponent* transformReference = this->GetAllComponents()[i].get();

			TransformComponent* test = dynamic_cast<TransformComponent*>(transformReference);

			m_Position = test->GetPosition();

			break;
		}
	}
}
void GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	m_Components.push_back(component);
}
std::shared_ptr<BaseComponent> GameObject::GetComponent(BaseComponent componentType) const
{
	std::shared_ptr<BaseComponent> getComponent{};

	for (size_t i{}; i < this->GetAllComponents().size(); ++i)
	{
		if (typeid(this->GetAllComponents()[i]) == typeid(componentType))
		{
			getComponent = this->GetAllComponents()[i];
			break;
		}
	}
	return getComponent;
}