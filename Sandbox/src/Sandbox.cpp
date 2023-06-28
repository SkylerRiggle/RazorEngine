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
	LOG(scene->HasComponent<int>(entity));
	scene->RemoveComponent<int>(entity);
	LOG(scene->HasComponent<int>(entity));
	scene->DestroyEntity(entity);

	// Logger Testing
	LOG("Testing Logger Statement.");
	WARN("Testing Warning Statement.");
	ASSERT(entity == NULL); // Should not trigger
	//ASSERT(false) // Should trigger

	// Event System Testing
	bool isRunning = true;

	// Update Testing
	while (isRunning)
	{
		window->Update();
	}

	// Cleanup
	delete window;
	delete scene;

	return 0;
}