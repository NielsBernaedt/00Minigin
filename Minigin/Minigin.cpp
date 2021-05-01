#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>

#include "FPSComponent.h"
#include "RenderComponents.h"
#include "GameObject.h"
#include "Scene.h"
#include "Texture2D.h"

using namespace std;
using namespace std::chrono;

void Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	auto background = std::make_shared<GameObject>();
	std::shared_ptr<Texture2D> backgroundTexture = ResourceManager::GetInstance().LoadTexture("background.jpg");
	const std::shared_ptr<TextureRenderComponent> backgroundRenderComp = std::make_shared<TextureRenderComponent>(background.get(), backgroundTexture, 0, 0, 1000, 1000);
	background->AddComponent(backgroundRenderComp);
	scene.Add(background);

	auto logo = std::make_shared<GameObject>();
	std::shared_ptr<Texture2D> logoTexture = ResourceManager::GetInstance().LoadTexture("logo.png");
	const std::shared_ptr<TextureRenderComponent> logoRenderComp = std::make_shared<TextureRenderComponent>(logo.get(), logoTexture, 0, 300, 200, 150);
	logo->AddComponent(logoRenderComp);
	scene.Add(logo);

	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	auto fpsCounterObject = std::make_shared<GameObject>();
	const std::shared_ptr<FPSComponent> fpsComponent = std::make_shared<FPSComponent>( fpsCounterObject.get() );
	fpsCounterObject->AddComponent(fpsComponent);
	scene.Add(fpsCounterObject);

	auto textTest = std::make_shared<GameObject> ();
	const std::shared_ptr<TextRenderComponent> textComp = std::make_shared<TextRenderComponent>(textTest.get(),font, "Programming 4 Assignment", 100, 100);
	textTest->AddComponent(textComp);
	scene.Add(textTest);
}

void Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}
//second push test
void Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		bool doContinue = true;
		auto lastTime = std::chrono::high_resolution_clock::now();
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			const float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
			lastTime = currentTime;
			
			doContinue = input.ProcessInput();
			sceneManager.Update(deltaTime);
			renderer.Render();
			
			auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(m_MsPerFrame) - high_resolution_clock::now());
			this_thread::sleep_for(sleepTime);
		}
	}

	Cleanup();
}
