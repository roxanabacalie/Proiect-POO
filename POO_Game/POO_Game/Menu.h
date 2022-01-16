#pragma once
#include <SDL.h>
#include "GameState.h"

class Menu : public GameState
{
public:
	Menu();
	~Menu();

	void init(SDL_Window *window1, SDL_Renderer *renderer1);
	void handleEvents(int &k, bool quit);
	//void update();
	void render();
	void clean();

	//bool running() const { return isRunning; }

};
