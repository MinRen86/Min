#pragma once

#ifdef MN_PLATFORM_WINDOWS

	extern Min::Application* Min::CreateApplication();

	int main(int argc, char** argv)
	{
		auto app = Min::CreateApplication();
		app->Run();
		delete app;
	}
#endif