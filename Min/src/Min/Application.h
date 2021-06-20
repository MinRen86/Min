#pragma once

#include <Min/Core.h>
#include <Min/Events/Event.h>

namespace Min
{
	class MIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in CLIENT
	Application* CreateApplication();
}

