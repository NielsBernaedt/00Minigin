#pragma once
#include "BaseComponent.h"

#include "TextComponent.h"

class TextComponent; //only temporary, Still figuring out how Components work with eachother, without the owner interfering.

class FPSComponent : public BaseComponent
{
public:
	void Update(float deltaTime) override;
	void Render() const override;
	
	FPSComponent();
	~FPSComponent() override;
	FPSComponent(const FPSComponent& other) = delete;
	FPSComponent(FPSComponent&& other) = delete;
	FPSComponent& operator=(const FPSComponent& other) = delete;
	FPSComponent& operator=(FPSComponent&& other) = delete;

private:
	int m_FramesPerSecond = 0;
	std::shared_ptr < TextComponent > FPSCounter;
};
