#pragma once

#ifdef MN_PLATFORM_WINDOWS

	extern Min::Application* Min::CreateApplication();

	int main(int argc, char** argv)
	{
		Min::Log::Init();
		MN_CORE_WARN("Initialized Log!");
		int a{ 5 };
		MN_INFO("Hello! Var = {0}", a);
		auto app = Min::CreateApplication();
		app->Run();
		delete app;
	}
#endif