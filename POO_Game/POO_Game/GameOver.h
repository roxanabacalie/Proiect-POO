#pragma once
#pragma once
#include <SDL.h>
#include "GameState.h"

class GameOver : public GameState
{
public:
	GameOver();
	~GameOver();

	void initObjects(SDL_Window* window1, SDL_Renderer* renderer1, bool lost);
	void handleEvents(int& k);
	void update();
	void render();
	void clean();
	bool running() const { return isRunning; }
	void initWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
