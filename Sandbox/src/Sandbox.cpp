#include <Razor.h>

Razor::Game* Razor::CreateGame()
{
	// Populate the default game data.
	Razor::GameData gameData{};
	gameData.windowData.title = "Sandbox Game";
	gameData.windowData.screenWidth = 800;
	gameData.windowData.screenHeight = 600;

	// Return a new game application reference.
	return new Razor::Game(gameData);
}