//Using SDL and standard IO
#include "Game.h"
#include "Menu.h"
#include "GameState.h"
#include "GameOver.h"
#include <SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

int main(int argc, char* args[])
{
	const int fps = 100;
	// max time between frames
	const int frameDelay = 1000 / fps;
	
	int k1 = 1;
	while (k1 == 1)
	{
		Game* game = new Game();
		Menu* menu = new Menu();
		GameOver* gameover = new GameOver();
		bool quit = false;
		gameover->initWindow("PacMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
		menu->init(gameover->GetWindow(), gameover->GetRenderer());
		game->init(gameover->GetWindow(), gameover->GetRenderer());
		int k = 0;

		while (menu->running())
		{
			Uint32 frameStart = SDL_GetTicks();
			menu->handleEvents(k, quit);
				menu->render();
				const int frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}
		}
		menu->clean();
		delete menu;


		switch (k)
		{
		case 4:
			game->clean();
			//delete game;
			quit = true;
			break;
		case 1:
			game->level = 1;
			game->initObjects();
			while (game->running())
			{
				Uint32 frameStart = SDL_GetTicks();
				game->handleEvents(quit);
				game->update();
				game->render();
				//if(game->GetNrDots==6)
				//	game->isRunning
				const int frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}


			}
			//game->clean();
			//delete game;
			break;
		case 2:
			game->level = 2;
			game->initObjects();
			while (game->running())
			{
				Uint32 frameStart = SDL_GetTicks();
				game->handleEvents(quit);
				game->update();
				game->render();
				const int frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}
			}
			//game->clean();
			//delete game;
			break;
		case 3:
			game->level = 3;
			game->initObjects();
			while (game->running())
			{
				Uint32 frameStart = SDL_GetTicks();
				game->handleEvents(quit);
				game->update();
				game->render();
				const int frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}


			}
			//game->clean();
			//delete game;
			break;
		default:
			break;
		}

		if (quit)
			k1 = 0;
		//std::cout << game->lost;
		if (!quit)
		{
			gameover->initObjects(gameover->GetWindow(), gameover->GetRenderer(), game->lost);
			delete game;
			while (gameover->running())
			{
				Uint32 frameStart = SDL_GetTicks();
				gameover->handleEvents(k1);
				gameover->render();
				const int frameTime = SDL_GetTicks() - frameStart;

				if (frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}

			}
		}

		gameover->clean();
		delete gameover;

	}
	return 0;
}