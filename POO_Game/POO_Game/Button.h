#pragma once
#pragma once
#include "Component.h"
#include "SDL.h"

class Button : public Component
{

private:
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};
	Button() = default;
	Button(const char* path, SDL_Renderer* renderer);
	void setTex(const char* path);
	void init() override;
	void draw() override;
public:
	friend class Menu;
	friend class GameOver;
};
