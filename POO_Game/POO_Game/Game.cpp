
#include "Game.h"
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

Map* map;

Player* player;
Enemy* enemy1;
Enemy* enemy2;
Enemy* enemy3;
Enemy* enemy4;
Enemy* enemy5;
Enemy* enemy6;
Enemy* enemy7;
Enemy* enemy8;
Enemy* enemy9;
Enemy* enemy10;
Enemy* enemy11;
Enemy* enemy12;
Enemy* enemy13;

int ok;

Game::Game() : GameState()
{
}

Game::~Game()
{
	delete player;
	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete enemy4;
	delete enemy5;
	delete enemy6;
	if (level == 2)
	{
		delete enemy7;
		delete enemy8;
	}
	if (level == 3)
	{
		delete enemy9;
		delete enemy10;
		delete enemy11; 
		delete enemy12;
		delete enemy13;
	}
}



//initializam playerul si fantomele
void Game::initObjects()
{
	player = new Player("assets/Walk_9.png", renderer);
	enemy1 = new Enemy("assets/redghost.png", renderer);
	enemy2 = new Enemy("assets/blueghost.png", renderer);
	enemy3 = new Enemy("assets/pinkghost.png", renderer);
	enemy4 = new Enemy("assets/orangeghost.png", renderer);
	enemy5 = new Enemy("assets/purpleghost.png", renderer);
	enemy6 = new Enemy("assets/blueghost2.png", renderer);
	enemy1->init(1);
	enemy2->init(2);
	enemy3->init(3);
	enemy4->init(4);
	enemy5->init(5);
	enemy6->init(6);
	if (level == 1)
	{
		map = new Map(renderer, 1);
	}
	else
	{
		enemy7 = new Enemy("assets/greenghost.png", renderer);
		enemy7->init(7);
		enemy8 = new Enemy("assets/greenghost2.png", renderer);
		enemy8->init(8);

		if (level == 2)
		{
			map = new Map(renderer, 2);
			
		}
		else
		{
			map = new Map(renderer, 3);


			enemy9 = new Enemy("assets/purpleghost.png", renderer);
			enemy9->init(9);
			enemy10 = new Enemy("assets/orangeghost.png", renderer);
			enemy10->init(10);
			enemy11 = new Enemy("assets/pinkghost.png", renderer);
			enemy11->init(11);


			enemy12 = new Enemy("assets/blueghost2.png", renderer);
			enemy12->init(12);
			enemy13 = new Enemy("assets/greenghost2.png", renderer);
			enemy13->init(13);
		}
	}
	
	player->init();
	
}

void Game::handleEvents(bool &quit)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
	{
		isRunning = false;
		quit = 1;
		break;
	}
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			ok = 1;
			break;
		case SDLK_LEFT:
			ok = 2;
			break;
		case SDLK_DOWN:
			ok = 3;
			break;
		case SDLK_RIGHT:
			ok = 4;
			break;
		}
		break;
	case SDL_KEYUP:
		ok = 0;
		break;
	default:
		break;
	}
	if (level == 1)
	{
		if (enemy1->CheckCollisionWithPlayer(player) || enemy2->CheckCollisionWithPlayer(player) || enemy3->CheckCollisionWithPlayer(player) || enemy4->CheckCollisionWithPlayer(player) || enemy5->CheckCollisionWithPlayer(player) || enemy6->CheckCollisionWithPlayer(player))
			isRunning = false;
	}
	if (level == 2)
	{
		if (enemy1->CheckCollisionWithPlayer(player) || enemy2->CheckCollisionWithPlayer(player) || enemy3->CheckCollisionWithPlayer(player) || enemy4->CheckCollisionWithPlayer(player) || enemy5->CheckCollisionWithPlayer(player) || enemy6->CheckCollisionWithPlayer(player) || enemy7->CheckCollisionWithPlayer(player) || enemy8->CheckCollisionWithPlayer(player))
			isRunning = false;
	}
	if (level == 3)
	{
		if (enemy1->CheckCollisionWithPlayer(player) || enemy2->CheckCollisionWithPlayer(player) || enemy3->CheckCollisionWithPlayer(player) || enemy4->CheckCollisionWithPlayer(player) || enemy5->CheckCollisionWithPlayer(player) || enemy6->CheckCollisionWithPlayer(player) || enemy7->CheckCollisionWithPlayer(player) || enemy8->CheckCollisionWithPlayer(player) || enemy9->CheckCollisionWithPlayer(player) || enemy10->CheckCollisionWithPlayer(player) || enemy11->CheckCollisionWithPlayer(player) ||enemy12->CheckCollisionWithPlayer(player) || enemy13->CheckCollisionWithPlayer(player))
			isRunning = false;
	}
	/*if (GetNrDots() > 50)
		std::cout << GetNrDots()<<' ';*/
	//std::cout << "Nr max puncte: " << map->nrMaxDots;
	if (GetNrDots() == map->nrMaxDots)
	{
		isRunning = false;
		lost = false;
	}
}

bool dir1 = 0;
bool dir2 = 1;
bool dir3 = 0;
bool dir4 = 0;
bool dir5 = 0;
bool dir6 = 0;
bool dir7 = 0;
bool dir8 = 0;

bool dir9 = 0;
bool dir10 = 0;
bool dir11 = 0;
bool dir12 = 0;
bool dir13 = 1;

void Game::update()
{
	player->move(ok, level);
	dir1 = enemy1->move(1, dir1, level);
	dir2 = enemy2->move(1, dir2, level);
	dir3 = enemy3->move(1, dir3, level);
	dir4 = enemy4->move(1, dir4, level);
	dir5 = enemy5->move(2, dir5, level);
	dir6 = enemy6->move(2, dir6, level);

	if (level == 2) {
		dir7 = enemy7->move(2, dir7, level);
		dir8 = enemy8->move(2, dir8, level);
	}

	if (level == 3) {
		dir7 = enemy7->move(2, dir7, level);
		dir8 = enemy8->move(2, dir8, level);

		dir9 = enemy9->move(2, dir9, level);
		dir10 = enemy10->move(2, dir10, level);
		dir11 = enemy11->move(1, dir11, level);

		dir12 = enemy12->move(1, dir12, level);
		dir13 = enemy13->move(1, dir13, level);
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap(player->destRect.x, player->destRect.y);
	player->draw();
	enemy1->draw();
	enemy2->draw();
	enemy3->draw();
	enemy4->draw();
	enemy5->draw();
	enemy6->draw();
	if (level == 2)
	{
		enemy7->draw();
		enemy8->draw();
	}

	if (level == 3)
	{
		enemy7->draw();
		enemy8->draw();

		enemy9->draw();
		enemy10->draw();
		enemy11->draw();

		enemy12->draw();
		enemy13->draw();
	}

	SDL_RenderPresent(renderer);
}
int Game::GetNrDots()
{
	return map->nrDots;
}
void Game::clean()
{
	//SDL_DestroyWindow(window);
	//SDL_DestroyRenderer(renderer);
	//SDL_QUIT;
	std::cout << "Game cleaned" << std::endl;
}

void Game::init(SDL_Window* window1, SDL_Renderer* renderer1)
{

	window = window1;
	renderer = renderer1;
	isRunning = true;
}

