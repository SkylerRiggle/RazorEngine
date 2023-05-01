#pragma once

#ifdef RZ_PLATFORM_WINDOWS

extern Razor::Game* Razor::CreateGame();

int main(int argc, char* argv[])
{
	auto game = Razor::CreateGame();
	game->StartGame();
	delete game;

	return 0;
}

#endif // RZ_PLATFORM_WINDOWS
