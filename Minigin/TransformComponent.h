#pragma once
#include "BaseComponent.h"
#include <glm/vec3.hpp>

class TransformComponent final : public BaseComponent
{
public:
	TransformComponent(GameObject* gameObject, glm::vec3 position);
	~TransformComponent() override = default;
	TransformComponent(const TransformComponent& other) = delete;
	TransformComponent(TransformComponent&& other) = delete;
	TransformComponent& operator=(const TransformComponent& other) = delete;
	TransformComponent& operator=(TransformComponent&& other) = delete;
	
	const glm::vec3& GetPosition() const;
	void SetPosition(float x, float y, float z);
private:
	glm::vec3 m_Position;
};
