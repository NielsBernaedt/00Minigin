#include "MiniginPCH.h"
#include "TransformComponent.h"

TransformComponent::TransformComponent(GameObject* gameObject, glm::vec3 position)
	: BaseComponent( gameObject )
	, m_Position{ position }
{
}

const glm::vec3& TransformComponent::GetPosition() const
{
	return m_Position;
}

void TransformComponent::SetPosition(float x, float y, float z)
{
	m_Position = { x, y, z };
}