#pragma once
//#include "BaseComponent.h"
//#include <glm/vec3.hpp>
//
//class CollisionComponent : public BaseComponent
//{
//public:
//	void Update(float deltaTime) override;
//	//void Render() const override ; no need to render a  hitbox
//
//	CollisionComponent(glm::vec3 bottomLeft, int width, int height);
//	~CollisionComponent() override;
//	CollisionComponent(const CollisionComponent& other) = delete;
//	CollisionComponent(CollisionComponent&& other) = delete;
//	CollisionComponent& operator=(const CollisionComponent& other) = delete;
//	CollisionComponent& operator=(CollisionComponent&& other) = delete;
//private:
//	glm::vec3 m_BottomLeft;
//	int m_Width;
//	int m_Height;
//};