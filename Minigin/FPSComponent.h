#pragma once
#include "BaseComponent.h"

class TextRenderComponent;

class FPSComponent : public BaseComponent
{
public:
	void Update(float deltaTime) override;
	void Render() const override;
	
	FPSComponent( GameObject* gameObject );
	~FPSComponent() override = default;
	FPSComponent(const FPSComponent& other) = delete;
	FPSComponent(FPSComponent&& other) = delete;
	FPSComponent& operator=(const FPSComponent& other) = delete;
	FPSComponent& operator=(FPSComponent&& other) = delete;

private:
	int m_FramesPerSecond = 0;
	std::shared_ptr <TextRenderComponent> FPSCounter;
};
