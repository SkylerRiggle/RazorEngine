#include "Game.h"

using namespace Razor;

Game::Game(GameData gameData)
{
	// Create the application's window
	window = std::make_unique<Window>();
}

Game::~Game()
{
	// Destroy the game window
	window.reset();
}

void Game::StartGame()
{
	while (true)
	{
		window->Update();
	}
}