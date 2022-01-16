#include <SDL.h>
#include <iostream>
#include "Player.h"
#include "TextureManager.h"

int level1[20][25] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,1},

	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1},
	{1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1},

	{1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,0,1},

	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,1},
	{1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int level2[20][25] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1},

	{1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
	{1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
	{1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,1,1,1,1},

	{1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,1},

	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};



int level3[20][25] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1},

	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1},
	{1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},

	{1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,1,1,0,0,0,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},

	{1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

MovingComponent::MovingComponent(const char* path, SDL_Renderer* renderer) : renderer(renderer)
{
	setTex(path);
}

void MovingComponent::setTex(const char* path)
{
	texture = TextureManager::LoadTexture(path, renderer);
}


void MovingComponent::init()
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 32;
	destRect.x = destRect.y = 32;
	destRect.w = destRect.h = 25;
}

void MovingComponent::update()
{
	destRect.x++;
	destRect.y++;
}


int Rectangles(SDL_Rect v[], int lvl[20][25])
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 1; i < 19; ++i)
	{
		for (j = 1; j < 24; ++j)
		{
			if (lvl[i][j] == 1 && j<24)
			{
				v[k].x = j * 32;
				v[k].y = i * 32;
				v[k].h = 32;
				v[k].w = 32;
				++j;
				while (lvl[i][j] == 1 && j<24)
				{
					++j;
					v[k].w = v[k].w + 32;
				}
				k = k + 1;
			}	
		}
	}
	return k;
}

int RectanglesDot(SDL_Rect v[], int lvl[20][25])
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 1; i < 19; ++i)
	{
		for (j = 1; j < 24; ++j)
		{
			if (lvl[i][j] == 0 && j < 24)
			{
				v[k].x = j * 32;
				v[k].y = i * 32;
				v[k].h = 32;
				v[k].w = 32;
				k = k + 1;
			}
		}
	}
	return k;
}

bool MovingComponent::CollisionCheckLeft(SDL_Rect A, SDL_Rect B)
{
	//A e dreptunghiul, B e playerul

	//The sides of the rectangles
	unsigned int LeftA, LeftB;
	unsigned int RightA, RightB;
	unsigned int TopA, TopB;
	unsigned int BottomA, BottomB;

	//Get the sizes from the SDL_Rect structs - Rect A
	LeftA = A.x;
	RightA = A.x + A.w;
	TopA = A.y;
	BottomA = A.y + A.h;

	//Get the sizes from the SDL_Rect structs - Rect B
	LeftB = B.x;
	RightB = B.x + B.w;
	TopB = B.y;
	BottomB = B.y + B.h;

	if (LeftB == RightA && TopB<BottomA && BottomB>TopA)
		return true;
	else
		return false;
}

bool MovingComponent::CollisionCheckRight(SDL_Rect A, SDL_Rect B)
{
	//A e dreptunghiul, B e playerul

	//The sides of the rectangles
	unsigned int LeftA, LeftB;
	unsigned int RightA, RightB;
	unsigned int TopA, TopB;
	unsigned int BottomA, BottomB;

	//Get the sizes from the SDL_Rect structs - Rect A
	LeftA = A.x;
	RightA = A.x + A.w;
	TopA = A.y;
	BottomA = A.y + A.h;

	//Get the sizes from the SDL_Rect structs - Rect B
	LeftB = B.x;
	RightB = B.x + B.w;
	TopB = B.y;
	BottomB = B.y + B.h;

	if (LeftA == RightB && TopB<BottomA && BottomB>TopA)
		return true;
	else
		return false;
}

bool MovingComponent::CollisionCheckUp(SDL_Rect A, SDL_Rect B)
{
	//A e dreptunghiul, B e playerul

	//The sides of the rectangles
	unsigned int LeftA, LeftB;
	unsigned int RightA, RightB;
	unsigned int TopA, TopB;
	unsigned int BottomA, BottomB;

	//Get the sizes from the SDL_Rect structs - Rect A
	LeftA = A.x;
	RightA = A.x + A.w;
	TopA = A.y;
	BottomA = A.y + A.h;

	//Get the sizes from the SDL_Rect structs - Rect B
	LeftB = B.x;
	RightB = B.x + B.w;
	TopB = B.y;
	BottomB = B.y + B.h;

	if (BottomA == TopB && RightB > LeftA && LeftB < RightA)
		return true;
	else
		return false;
}


bool MovingComponent::CollisionCheckDown(SDL_Rect A, SDL_Rect B)
{
	//A e dreptunghiul, B e playerul

	//The sides of the rectangles
	unsigned int LeftA, LeftB;
	unsigned int RightA, RightB;
	unsigned int TopA, TopB;
	unsigned int BottomA, BottomB;

	//Get the sizes from the SDL_Rect structs - Rect A
	LeftA = A.x;
	RightA = A.x + A.w;
	TopA = A.y;
	BottomA = A.y + A.h;

	//Get the sizes from the SDL_Rect structs - Rect B
	LeftB = B.x;
	RightB = B.x + B.w;
	TopB = B.y;
	BottomB = B.y + B.h;

	if (BottomB == TopA && RightB > LeftA && LeftB < RightA)
		return true;
	else
		return false;
}

SDL_Rect v1[100];
SDL_Rect v2[100];
SDL_Rect v3[100];
int length1 = Rectangles(v1, level1);
int length2 = Rectangles(v2, level2);
int length3 = Rectangles(v3, level3);
bool MovingComponent::intersection(int ok, int level)
{
	int length;
	SDL_Rect v[100];
	if (level == 1)
	{
		length = length1;
		for (int i = 0; i < length; ++i)
		{
			//v[i] = v1[i];
			v[i].x = v1[i].x;
			//std::cout << v1[i].x<<' ';
			v[i].y = v1[i].y;
			//std::cout << v1[i].y<<' ';
			v[i].w = v1[i].w;
			//std::cout << v1[i].w<<' ';
			v[i].h = v1[i].h;
			//std::cout << v1[i].h<<"\n";
		}
	}
	if (level == 2)
	{
		length = length2;
		for (int i = 0; i < length; ++i)
		{
			//v[i] = v2[i];
			v[i].x = v2[i].x;
			v[i].y = v2[i].y;
			v[i].w = v2[i].w;
			v[i].h = v2[i].h;

		}
	}
	if (level == 3)
	{
		length = length3;
		for (int i = 0; i < length; ++i)
		{
			//v[i] = v3[i];
			v[i].x = v3[i].x;
			v[i].y = v3[i].y;
			v[i].w = v3[i].w;
			v[i].h = v3[i].h;
		}
	}

	//std::cout << length;
	switch (ok)
	{
	case 1:
		for (int i = 0; i < length; ++i)
		{
			if (CollisionCheckUp(v[i], destRect))
				return true;
		}
		return false;
		break;
	case 2:
		for (int i = 0; i < length; ++i)
		{
			if (CollisionCheckLeft(v[i], destRect))
				return true;
		}
		return false;
		break;
	case 3:
		for (int i = 0; i < length; ++i)
		{
			if (CollisionCheckDown(v[i], destRect))
				return true;
		}
		return false;
		break;
	case 4:
		for (int i = 0; i < length; ++i)
		{
			if (CollisionCheckRight(v[i], destRect))
				return true;
		}
		return false;
		break;
	default:
		break;
	}
	delete []v;
}



void MovingComponent::draw()
{
	TextureManager::Draw(texture, srcRect, destRect, renderer);
}

SDL_Rect MovingComponent::getRect()
{
	return this->destRect;
}