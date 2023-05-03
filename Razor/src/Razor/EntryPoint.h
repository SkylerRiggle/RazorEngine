#pragma once

#ifdef RZ_PLATFORM_WINDOWS

extern Razor::Game* Razor::CreateGame();

// The application's entry point
int main(int argc, char* argv[])
{
	// Handle the lifetime of the game "application"
	auto game = Razor::CreateGame();
	game->StartGame();
	delete game;

	return 0;
}

#endif // RZ_PLATFORM_WINDOWS
