#pragma once
#pragma once
#include <SDL.h>

class GameState
{
public:
	GameState() {
		isRunning = false;
		window = nullptr;
		renderer = nullptr;
	};
	//~Gamestate();

	virtual void render()=0;
	virtual void clean()=0;
	bool running() const { return isRunning; }

protected:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
