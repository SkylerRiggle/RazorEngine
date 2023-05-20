#include <Razor.h>

int main(int argc, void* argv[])
{
	// Window Data Testing
	Razor::WindowData windowData = {};
	windowData.title = "Sandbox Application";
	windowData.screenWidth = 800;
	windowData.screenHeight = 700;
	windowData.vSync = true;

	// Window Creation Testing
	Razor::Window* window = Razor::Window::CreateWindow(windowData);

	// Basic Scene Testing
	Razor::Scene* scene = new Razor::Scene();
	Entity entity = scene->CreateEntity();
	scene->AddComponent<int>(entity, 5);
	std::printf("%d\n", scene->HasComponent<int>(entity));
	scene->RemoveComponent<int>(entity);
	std::printf("%d\n", scene->HasComponent<int>(entity));
	scene->DestroyEntity(entity);
	ASSERT(entity == NULL);

	// Update Testing
	while (true)
	{
		window->Update();
	}

	return 0;
}