#pragma once
#ifdef MAR_PLATFORM_WINDOWS

extern Mar::Application* Mar::CreateApplication();

int main(int argc, char** argv)
{
	Mar::Log::Init();
	MAR_CORE_WARN("Initialized");
	MAR_INFO("Hello");
	auto app = Mar::CreateApplication();
	app->Run();
	delete app;
}
#endif // MAR_PLATFORM_WINDOWS
