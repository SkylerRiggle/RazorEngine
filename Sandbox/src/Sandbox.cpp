#include <Razor.h>

Razor::Game* Razor::CreateGame()
{
	// Populate the default game data.
	Razor::GameData gameData{};
	gameData.title = "Sandbox Game";
	gameData.defaultWidth = 800;
	gameData.defaultHeight = 600;

	// Return a new game application reference.
	return new Razor::Game(gameData);
}