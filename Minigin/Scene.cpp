#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"


unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
}

void Scene::Update(float deltaTime)
{
	for(auto& object : m_Objects)
	{
		object->Update(deltaTime);
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Render();

		std::vector<std::shared_ptr<BaseComponent>> components = object->GetAllComponents();
		for (const auto& comp : components)
		{
			comp->Render();
		}
	}
}