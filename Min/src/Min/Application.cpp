#include <Min/Application.h>
#include <Min/Events/ApplicationEvent.h>
#include <Min/Log.h>

namespace Min
{

	Application::Application() {}

	Application::~Application() {}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MN_TRACE(e);

		while (true);
	}
}