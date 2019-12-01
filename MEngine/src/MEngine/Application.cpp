#include "Application.h"
#include "../Helpers.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
Application::Application()
{
	Init();
}


void Application::Init()
{
	glfwInit();
	m_window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
	m_input = std::make_unique<Input>(m_window);
	glfwSetKeyCallback(m_window, Input::keyCallback);
	InputComponent* test = new InputComponent(17, 1, 0);
	m_input->add(test);
}

void Application::Run()
{

	while (!glfwWindowShouldClose(m_window))
	{
		int a = 12;
		glfwPollEvents();
	}
}

Application::~Application()
{
	delete test;
}


void Print()
{
	std::cout << "Hello World!" << std::endl;
}
