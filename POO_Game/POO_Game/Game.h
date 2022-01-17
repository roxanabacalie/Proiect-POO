#pragma once
#include <SDL.h>
#include "GameState.h"

class Game: public GameState 
{
private:
	int GetNrDots();
public:
	Game();
	~Game();

	void initObjects();
	void handleEvents(bool &quit);
	void update();
	void render();
	void init(SDL_Window* window1, SDL_Renderer* renderer1);
	
	bool lost = true;
	int level;
};
