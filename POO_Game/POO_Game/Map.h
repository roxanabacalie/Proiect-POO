#pragma once
#include <SDL_image.h>


class Map
{
public:
	Map(SDL_Renderer* renderer, int level);
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap(int x, int y);
	int nrDots;
	int nrMaxDots;
	bool eaten[20][25];
private:
	SDL_Renderer* renderer;
	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* dot;

	int map[20][25];
};