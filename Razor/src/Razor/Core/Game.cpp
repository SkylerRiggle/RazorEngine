#include "Game.h"

using namespace Razor;

// Default application running flag value
bool Game::s_applicationRunning = false;

Game::Game(GameData gameData)
{
	// Create the application's window
	m_window = Window::CreateWindow(gameData.windowData);
}

Game::~Game()
{
	// Destroy the game window
	delete m_window;
}

void Game::StartGame()
{
	// Mark the application to begin running
	s_applicationRunning = true;

	// Game loop
	while (s_applicationRunning)
	{
		m_window->Update();
	}
}