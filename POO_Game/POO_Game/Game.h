#pragma once
#include <SDL.h>
#include "GameState.h"

class Game: public GameState
{
public:
	Game();
	~Game();

	void initObjects();
	void handleEvents(bool &quit);
	void update();
	void render();
	void clean();
	void init(SDL_Window* window1, SDL_Renderer* renderer1);
	int GetNrDots();
	bool lost = true;
	int level=0;

//private:
	/*bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;*/
};
