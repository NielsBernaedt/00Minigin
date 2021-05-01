#include "MiniginPCH.h"
#include "FPSComponent.h"

#include "GameObject.h"
#include "ResourceManager.h"
#include "RenderComponents.h"
#include "Renderer.h"

FPSComponent::FPSComponent(GameObject* gameObject)
	: BaseComponent( gameObject )
{
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	FPSCounter = std::make_shared<TextRenderComponent>(m_OwnerObject, font, "144:", 0, 0);

	m_OwnerObject->AddComponent(FPSCounter);
}

void FPSComponent::Update(float deltaTime)
{
	m_FramesPerSecond = int(1.0f / deltaTime);
	FPSCounter->SetText(std::to_string(m_FramesPerSecond));
}

void FPSComponent::Render() const
{
	FPSCounter->Render();
}