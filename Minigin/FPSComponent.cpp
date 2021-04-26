#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "ResourceManager.h"
#include "TextComponent.h"

FPSComponent::FPSComponent()
{
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	FPSCounter = std::make_shared<TextComponent>("144:", font);
	FPSCounter->SetPosition(0, 50);
}
FPSComponent::~FPSComponent()
{
}


void FPSComponent::Update(float deltaTime)
{
	m_FramesPerSecond = int(1.0f / deltaTime);
	FPSCounter->SetText(std::to_string(m_FramesPerSecond));
	FPSCounter->Update(deltaTime);
}

void FPSComponent::Render() const
{
	FPSCounter->Render();
}
