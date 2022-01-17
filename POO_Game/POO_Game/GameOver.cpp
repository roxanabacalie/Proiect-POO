#pragma once

#include "GameOver.h"
#include "Button.h"
#include "Map.h"
#include <iostream>


Button* PlayAgain; //buton play again
Button* Quit; //buton quit
Button* YouLost; //fundalul YouLost

GameOver::GameOver() : GameState()
{
}

GameOver::~GameOver()
{
	std::cout << "Destructor GameOver\n";
	delete PlayAgain;
	delete Quit;
	delete YouLost;
}


void GameOver::initObjects(SDL_Window* window1, SDL_Renderer* renderer1, bool lost)
{

	window = window1;
	renderer = renderer1;
	isRunning = true;

	if(lost)
		YouLost = new Button("assets/lost.png", renderer);
	else
		YouLost = new Button("assets/win.png", renderer);
	PlayAgain = new Button("assets/mainmenu.png", renderer);
	Quit = new Button("assets/quit.png", renderer);

	PlayAgain->init();
	YouLost->init();
	Quit->init();
	YouLost->destRect.x = 0;
	YouLost->destRect.y = 0;
	YouLost->destRect.w = 800;
	YouLost->destRect.h = 640;
	PlayAgain->destRect.y = 300;
	Quit->destRect.y = 450;
}


void GameOver::handleEvents(int& k)
{

	SDL_Event event;
	SDL_PollEvent(&event);
	Uint32 buttons;
	int x, y;
	buttons = SDL_GetMouseState(&x, &y);
	if ((x > PlayAgain->destRect.x) && (x < (PlayAgain->destRect.x + PlayAgain->destRect.w)) && (y > PlayAgain->destRect.y) && (y < (PlayAgain->destRect.y + PlayAgain->destRect.h)))
	{
		int blend = SDL_SetTextureAlphaMod(PlayAgain->texture, 120);
		int blend1 = SDL_SetTextureAlphaMod(Quit->texture, 255);
		//int blend2 = SDL_SetTextureAlphaMod(level3->texture, 255);
	}
	else
	{
		int blend = SDL_SetTextureAlphaMod(PlayAgain->texture, 255);
		if ((x > Quit->destRect.x) && (x < (Quit->destRect.x + Quit->destRect.w)) && (y > Quit->destRect.y) && (y < (Quit->destRect.y + Quit->destRect.h)))
		{
			int blend1 = SDL_SetTextureAlphaMod(Quit->texture, 120);
			//int blend2 = SDL_SetTextureAlphaMod(level3->texture, 255);
		}
		else
		{
			int blend1 = SDL_SetTextureAlphaMod(Quit->texture, 255);
		}
	}

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		k = 4;
		break;
	case SDL_MOUSEBUTTONDOWN:

		if ((x > PlayAgain->destRect.x) && (x < (PlayAgain->destRect.x + PlayAgain->destRect.w)))
		{
			if ((y > PlayAgain->destRect.y) && (y < (PlayAgain->destRect.y + PlayAgain->destRect.h)))
			{
				k = 1;
				isRunning = false;
			}
			else
			{
				if ((y > Quit->destRect.y) && (y < (Quit->destRect.y + Quit->destRect.h)))
				{
					k = 2;
					isRunning = false;
				}
			}
		}
		break;
	default:
		break;

	}
}

void GameOver::render()
{
	SDL_RenderClear(renderer);
	YouLost->draw();
	PlayAgain->draw();
	Quit->draw();
	//level3->draw();
	SDL_RenderPresent(renderer);
}

void GameOver::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game over cleaned" << std::endl;
}

SDL_Window* GameOver::GetWindow()
{
	return window;
}
SDL_Renderer* GameOver::GetRenderer()
{
	return renderer;
}

void GameOver::initWindow(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;
		auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != nullptr)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

