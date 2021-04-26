#pragma once
#include "BaseComponent.h"
#include "Transform.h"
#include "SceneObject.h"

class Texture2D;
class GameObject final : public SceneObject 
{
public:
	void Update(float deltaTime) override;
	void Render() const override;

	void SetTexture(const std::string& filename);
	void SetPosition(float x, float y);
	void AddComponent(std::shared_ptr<BaseComponent> component);

	GameObject() = default;
	virtual ~GameObject();
	GameObject(const GameObject& other) = delete;
	GameObject(GameObject&& other) = delete;
	GameObject& operator=(const GameObject& other) = delete;
	GameObject& operator=(GameObject&& other) = delete;

private:
	Transform m_Transform;
	std::shared_ptr<Texture2D> m_Texture{}; //Is not supposed to be here, change in future
	std::vector<std::shared_ptr<BaseComponent>> m_Components{};
};