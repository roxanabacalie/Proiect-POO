#pragma once
#include "MovingComponent.h"
#include "SDL.h"

class Player : public MovingComponent
{
	friend class Enemy;
	friend class Game;
public:
	Player() = default;
	Player(const char* path, SDL_Renderer* renderer);
	void move(int ok, int level);
};
