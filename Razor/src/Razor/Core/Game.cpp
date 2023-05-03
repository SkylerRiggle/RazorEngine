#include "Game.h"

using namespace Razor;

Game::Game(GameData gameData)
{
	// Create the application's window
	window = std::make_unique<Window>(CreateWindow());
}

Game::~Game()
{

}

void Game::StartGame()
{
	while (true);
}