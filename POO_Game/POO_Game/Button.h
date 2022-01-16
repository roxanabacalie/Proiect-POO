#pragma once
#pragma once
#include "Component.h"
#include "SDL.h"

class Button : public Component
{
protected:
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};

public:
	Button() = default;
	Button(const char* path, SDL_Renderer* renderer);

	void setTex(const char* path);
	void init() override;
	void update() {};
	void draw() override;
	bool intersection(int ok);
	
	friend class Menu;
	friend class GameOver;
};
