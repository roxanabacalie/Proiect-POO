#pragma once
#include "MovingComponent.h"
#include "Player.h"
#include "Game.h"
#include "SDL.h"

class Enemy : public MovingComponent
{
private:
	bool move(int ok, bool dir, int level);
	void init(int ok);
	bool CheckCollisionWithPlayer(Player* player);
public:
	Enemy() = default;
	Enemy(const char* path, SDL_Renderer* renderer);
	friend class Game;
};
