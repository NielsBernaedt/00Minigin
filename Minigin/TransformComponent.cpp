#include "MiniginPCH.h"
#include "TransformComponent.h"
#include "GameObject.h"

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
	//m_OwnerObject->SetPosition();
}