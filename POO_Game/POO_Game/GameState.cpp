#pragma once
#include <SDL.h>
#include "GameState.h"

GameState::GameState()
{
	isRunning = false;
	window = nullptr;
	renderer = nullptr;
}

/*GameState::~Gamestate()
{

}*/

bool GameState::running() const 
{ 
	return isRunning; 
}

