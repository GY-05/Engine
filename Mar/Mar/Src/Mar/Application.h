#pragma once
#include"Core.h"

namespace Mar {
	class MAR_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}
