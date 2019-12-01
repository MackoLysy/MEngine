#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include "Components/InputComponent.h"
#include "Core.h"
#include "Input.h"

struct GLFWwindow;

class Application
{
public:
	MGINE_API Application();
	MGINE_API void Run();
	MGINE_API ~Application();
private:
	void Init();
	std::unique_ptr<Input> m_input;
	GLFWwindow* m_window;
	InputComponent* test;
};

