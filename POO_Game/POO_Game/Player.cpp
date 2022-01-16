#include <SDL.h>
#include "Player.h"
#include "TextureManager.h"


Player::Player(const char* path, SDL_Renderer* renderer) : MovingComponent(path, renderer)
{
	setTex(path);
}


void Player::move(int ok, int level)
{
	
	SDL_Rect rect1 = { 64, 64, 128, 32 };
	switch (ok)
	{
	case 1:
		if(destRect.y>32 && !intersection(ok, level))
			destRect.y--;
		break;
	case 2:
		if(destRect.x>32 && !intersection(ok, level))
			destRect.x--;
		break;
	case 3:
		if(destRect.y<583 && !intersection(ok, level))
			destRect.y++;
		break;
	case 4:
		if (destRect.x < 743 && !intersection(ok, level))
			destRect.x++;
		break;
	default:
		break;
	}
}

