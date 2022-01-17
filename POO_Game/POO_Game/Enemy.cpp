#include <SDL.h>
#include "Enemy.h"
#include "PLayer.h"
#include "TextureManager.h"


Enemy::Enemy(const char* path, SDL_Renderer* renderer) : MovingComponent(path, renderer)
{
	setTex(path);
}


//Every ghost is in a different position
//in this function we decide where the ghost will be placed in the game depending on the parameter
void Enemy::init(int ok1)
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	switch (ok1) 
	{
	case 1:
		destRect.x = 387;
		destRect.y = 352;
		destRect.w = destRect.h = 32; 
		break;
	case 2:
		destRect.x = 450;
		destRect.y = 32;
		destRect.w = destRect.h = 32;
		break;
	case 3:
		destRect.x = 32;
		destRect.y = 576;
		destRect.w = destRect.h = 32;
		break;
	case 4:
		destRect.x = 320;
		destRect.y = 32;
		destRect.w = destRect.h = 32;
		break;
	case 5:
		destRect.x = 160;
		destRect.y = 160;
		destRect.w = destRect.h = 32;
		break;
	case 6:
		destRect.x = 608;
		destRect.y = 160;
		destRect.w = destRect.h = 32;
		break;
	case 7:
		destRect.x = 7*32;
		destRect.y = 4*32;
		destRect.w = destRect.h = 32;
		break;
	case 8:
		destRect.x = 17*32;
		destRect.y = 6*32;
		destRect.w = destRect.h = 32;
		break;
	case 9:
		destRect.x = 32;
		destRect.y = 11 * 32;
		destRect.w = destRect.h = 32;
		break;
	case 10:
		destRect.x = 23 * 32;
		destRect.y = 11 * 32;
		destRect.w = destRect.h = 32;
		break;
	case 11:
		destRect.x = 9 * 32;
		destRect.y = 7 * 32;
		destRect.w = destRect.h = 32;
		break;
	case 12:
		destRect.x = 32;
		destRect.y = 5 * 32;
		destRect.w = destRect.h = 32;
		break;
	case 13:
		destRect.x = 32 *23 ;
		destRect.y = 5 * 32;
		destRect.w = destRect.h = 32;
		break;
	default:
		break;
	}
}

//the enemy moves up/down or left/right depending on the ok parameter
//in this function we verify if the enemy collides with the walls
bool Enemy::move(int ok, bool dir, int level)
{
	switch (ok)
	{
	case 1:
		if (dir == 0)
		{
			if (!intersection(2, level)&&destRect.x>32)
			{
				destRect.x--;
				dir = 0;
			}
			else
			{
				destRect.x++;
				dir = 1;
			}
		}
		else 
		{
			if (!intersection(4, level)&&destRect.x<736)
			{
				destRect.x++;
				dir = 1;
			}
			else
			{
				destRect.x--;
				dir = 0;
			}
		}
		break;
	case 2:
		if (dir == 0)
		{
			if (!intersection(1, level) && destRect.y > 32)
			{
				destRect.y--;
				dir = 0;
			}
			else
			{
				destRect.y++;
				dir = 1;
			}
		}
		else
		{
			if (!intersection(3, level) && destRect.y < 576)
			{
				destRect.y++;
				dir = 1;
			}
			else
			{
				destRect.y--;
				dir = 0;
			}
		}
		break;
	default:
		break;
	}
	return dir;
	
}


//in this function we verify if the ghost (enemy) meets with the player
bool Enemy::CheckCollisionWithPlayer(Player *player)
{
	//The sides of the rectangles
	SDL_Rect PdestRect; 
	PdestRect.x=player->getRect().x;
	PdestRect.y = player->getRect().y;
	PdestRect.w = player->getRect().w;
	PdestRect.h = player->getRect().h;
	int leftPlayer, leftEnemy;
	int rightPlayer, rightEnemy;
	int topPlayer, topEnemy;
	int bottomPlayer, bottomEnemy;

	//Calculate the sides of rect A
	leftPlayer = PdestRect.x;
	rightPlayer = PdestRect.x + PdestRect.w;
	topPlayer = PdestRect.y;
	bottomPlayer = PdestRect.y + PdestRect.h;

	//Calculate the sides of rect B
	leftEnemy = this->destRect.x;
	rightEnemy = this->destRect.x + this->destRect.w;
	topEnemy = this->destRect.y;
	bottomEnemy = this->destRect.y + this->destRect.h;
	//If any of the sides from A are outside of B
	if (bottomPlayer <= topEnemy)
	{
		return false;
	}

	if (topPlayer >= bottomEnemy)
	{
		return false;
	}

	if (rightPlayer <= leftEnemy)
	{
		return false;
	}

	if (leftPlayer >= rightEnemy)
	{
		return false;
	} 
	return true;
}
