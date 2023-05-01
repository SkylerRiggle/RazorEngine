#include <Razor.h>

class Sandbox : public Razor::Game
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Razor::Game* Razor::CreateGame()
{
	return new Sandbox();
}