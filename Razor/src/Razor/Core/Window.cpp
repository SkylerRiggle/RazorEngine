#include "Window.h"

using namespace Razor;

#ifdef RZ_PLATFORM_WINDOWS

#include "../Platform/RZGLFWWindow.h"

Window* Window::CreateWindow(WindowData windowData)
{
	return new RZGLFWWindow(windowData);
}

#endif // RZ_PLATFORM_WINDOWS
