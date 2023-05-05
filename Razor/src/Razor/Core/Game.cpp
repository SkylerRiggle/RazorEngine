#include "Game.h"

using namespace Razor;

Game::Game(GameData gameData)
{
	// Create the application's window
	window = Window::CreateWindow(gameData.windowData);
}

Game::~Game()
{
	// Destroy the game window
	delete window;
}

void Game::StartGame()
{
	while (true)
	{
		window->Update();
	}
}