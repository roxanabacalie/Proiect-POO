
#include "Menu.h"
#include "Button.h"
#include "Map.h"
#include <iostream>

Button* level1;
Button* level2;
Button* level3;
Button* menu_button;

Menu::Menu() : GameState()
{
}

Menu::~Menu()
{
	delete level1;
	delete level2;
	delete level3;
	delete menu_button;
}



void Menu::init(SDL_Window *window1, SDL_Renderer *renderer1)
{
	
	window = window1;
	renderer = renderer1;
	isRunning = true;
	
	isRunning = true;
	menu_button = new Button("assets/menu.png", renderer);
	level1 = new Button("assets/level1.png", renderer);
	level2 = new Button("assets/level2.png", renderer);
	level3 = new Button("assets/level3.png", renderer);
	level1->init();
	level2->init();
	level3->init();
	menu_button->init();
	menu_button->destRect.x = 0;
	menu_button->destRect.y = 0;
	menu_button->destRect.w = 800;
	menu_button->destRect.h = 640;
	level1->destRect.y = 140;
	level2->destRect.y = 300;
	level3->destRect.y = 460;
}


void Menu::handleEvents(int &k, bool quit)
{
	
	SDL_Event event;
	SDL_PollEvent(&event);
	Uint32 buttons;
	int x, y;
	buttons = SDL_GetMouseState(&x, &y);
	if ((x > level1->destRect.x) && (x < (level1->destRect.x + level1->destRect.w)) && (y > level1->destRect.y) && (y < (level1->destRect.y + level1->destRect.h)))
	{
		int blend = SDL_SetTextureAlphaMod(level1->texture, 120);
		int blend1 = SDL_SetTextureAlphaMod(level2->texture, 255);
		int blend2 = SDL_SetTextureAlphaMod(level3->texture, 255);
	}
	else
	{ 
		int blend = SDL_SetTextureAlphaMod(level1->texture, 255);
		if ((x > level2->destRect.x) && (x < (level2->destRect.x + level2->destRect.w)) && (y > level2->destRect.y) && (y < (level2->destRect.y + level2->destRect.h)))
		{
			int blend1 = SDL_SetTextureAlphaMod(level2->texture, 120);
			int blend2 = SDL_SetTextureAlphaMod(level3->texture, 255);
		}
		else
		{
			int blend1 = SDL_SetTextureAlphaMod(level2->texture, 255);
			if ((x > level3->destRect.x) && (x < (level3->destRect.x + level3->destRect.w)) && (y > level3->destRect.y) && (y < (level3->destRect.y + level3->destRect.h)))
			{
				int blend2 = SDL_SetTextureAlphaMod(level3->texture, 120);
			}
			else
			{
				int blend2 = SDL_SetTextureAlphaMod(level3->texture, 255);
			}
		}
	}
	
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		quit = true;
		k = 4;
		break;
	case SDL_MOUSEBUTTONDOWN:
		
		if ((x > level1->destRect.x) && (x < (level1->destRect.x + level1->destRect.w)))
		{
			if ((y > level1->destRect.y) && (y < (level1->destRect.y + level1->destRect.h)))
			{
				k = 1;
				isRunning = false;
			}
			else
			{
				if ((y > level2->destRect.y) && (y < (level2->destRect.y + level2->destRect.h)))
				{
					k = 2;
					isRunning = false;
				}
				else
				{
					if ((y > level3->destRect.y) && (y < (level3->destRect.y + level3->destRect.h)))
					{
						k = 3;
						isRunning = false;
					}
				}
			}
		}
		break;
	default:
		break;

	}
}

void Menu::render()
{
	SDL_RenderClear(renderer);
	menu_button->draw();
	level1->draw();
	level2->draw();
	level3->draw();
	SDL_RenderPresent(renderer);
}

void Menu::clean()
{
	//SDL_DestroyWindow(window);
	//SDL_DestroyRenderer(renderer);
	//SDL_QUIT;
	std::cout << "Menu cleaned" << std::endl;
}
