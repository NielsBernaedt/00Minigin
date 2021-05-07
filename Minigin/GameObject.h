#pragma once
#include "BaseComponent.h"
#include <glm/vec3.hpp>

class Texture2D;

class GameObject final
{
public:
	void Update(float deltaTime);
	void Render() const;

	void SetPosition();
	void AddComponent(std::shared_ptr<BaseComponent> component);
	std::vector<std::shared_ptr<BaseComponent>> GetAllComponents() const { return m_Components; };
	std::shared_ptr<BaseComponent> GetComponent(BaseComponent componentType) const;

	GameObject() = default;
	~GameObject();
	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

private:
	std::vector<std::shared_ptr<BaseComponent>> m_Components{};
	glm::vec3 m_Position;
};