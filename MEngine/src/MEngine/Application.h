#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <list>

#include "Components/InputComponent.h"
#include "Core.h"
#include "Object.h"
#include "Input.h"

struct GLFWwindow;

class MGINE_API Application
{
public:
	Application();
	~Application();
	void addObject(Object*);
	void Run();

private:
	void Init();
	std::unique_ptr<Input> m_input;
	GLFWwindow* m_window;
	std::list<Object*> m_items;
	void Draw();
	void Update();
};

