#include <SDL.h>
#include <iostream>
#include "Button.h"
#include "TextureManager.h"



Button::Button(const char* path, SDL_Renderer* renderer) : renderer(renderer)
{
	setTex(path);
}


void Button::setTex(const char* path)
{
	texture = TextureManager::LoadTexture(path, renderer);
}


void Button::init()
{
	destRect.x = destRect.y = 150;
	destRect.w = 500;
	destRect.h = 100;
}

/*void Button::update()
{
	destRect.x = destRect.y = 32;
	destRect.w = destRect.h = 25;
}*/

void Button::draw()
{
	TextureManager::Draw(texture, srcRect, destRect, renderer);
}