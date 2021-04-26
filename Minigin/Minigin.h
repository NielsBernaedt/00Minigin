#pragma once
struct SDL_Window;

class Minigin
{
public:
	void Initialize();
	void LoadGame() const;
	void Cleanup();
	void Run();
private:
	static const int m_MsPerFrame = 16; //16 for 60 fps, 33 for 30 fps
	SDL_Window* m_Window{};
};