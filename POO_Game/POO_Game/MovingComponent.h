#pragma once
#include "Component.h"
#include "SDL.h"
#include "Map.h"

class MovingComponent : public Component
{
	friend class Game;
	//friend class Enemy;
protected:
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};

	bool CollisionCheckLeft(SDL_Rect A, SDL_Rect B);
	bool CollisionCheckRight(SDL_Rect A, SDL_Rect B);
	bool CollisionCheckUp(SDL_Rect A, SDL_Rect B);
	bool CollisionCheckDown(SDL_Rect A, SDL_Rect B);
	
	//int Rectangles(SDL_Rect[]);

public:
	MovingComponent() = default;
	MovingComponent(const char* path, SDL_Renderer* renderer);
	
	void setTex(const char* path);
	void init() override;
	void update() override;
	//void move(int ok);
	void draw() override;
	bool intersection(int ok, int level);
	SDL_Rect getRect();
	
};
