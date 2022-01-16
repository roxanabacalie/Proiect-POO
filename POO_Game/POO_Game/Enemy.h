#pragma once
#include "MovingComponent.h"
#include "Player.h"
#include "SDL.h"

class Enemy : public MovingComponent
{
	//SDL_Texture* texture{};
	//SDL_Renderer* renderer{};
	//SDL_Rect srcRect{}, destRect{};


public:
	Enemy() = default;
	Enemy(const char* path, SDL_Renderer* renderer);
	bool move(int ok, bool dir, int level);
	void init(int ok);
	bool CheckCollisionWithPlayer(Player* player);
};
