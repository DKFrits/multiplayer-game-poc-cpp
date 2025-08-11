#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Core/Log.h"

#include <chrono>

class ServerLayer : public Walnut::Layer
{
public:
	virtual void OnAttach() override 
	{

	}

	virtual void OnUpdate(float ts) override
	{
		WL_INFO("Server Timestep: {}", ts);

		using namespace std::chrono_literals;
		std::this_thread::sleep_for(5ms);
	}
private:
	bool m_AboutModalOpen = false;
};

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Server";

	Walnut::Application* app = new Walnut::Application(spec);
	std::shared_ptr<ServerLayer> serverLayer = std::make_shared<ServerLayer>();
	app->PushLayer(serverLayer);
	return app;
}

// https://youtu.be/W1MSxy90BLg?si=vVJc1NYX-n7mVdn9&t=2725