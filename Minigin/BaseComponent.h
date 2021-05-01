#pragma once

class GameObject;

class BaseComponent
{
public:
	BaseComponent(GameObject* gameObject) : m_OwnerObject{ gameObject } {};
	virtual ~BaseComponent(){};
	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(BaseComponent&& other) = delete;

	GameObject* GetOwner() const { return m_OwnerObject; };

	virtual void Update(float){};
	virtual void Render() const {};

protected:
	GameObject* m_OwnerObject;
};