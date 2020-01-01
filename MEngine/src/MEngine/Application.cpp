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
	if (!m_window)
	{
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_window);
	m_input = std::make_unique<Input>(m_window);
	glfwSetKeyCallback(m_window, Input::keyCallback);
	InputComponent* test = new InputComponent(17, 1, 0);
	m_input->add(test);
	glfwSwapInterval(1);
	const GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "GLEW Error: " << glewGetErrorString(err) << std::endl;
		exit(1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Application::Run()
{

	while (!glfwWindowShouldClose(m_window))
	{
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		Draw();
		Update();
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}

Application::~Application()
{

}

void Print()
{
	std::cout << "Hello World!" << std::endl;
}

void Application::addObject(Object* item)
{
	m_items.push_back(item);
}
void Application::Draw()
{
	for ( auto m_item : m_items)
	{
		m_item->draw();
	}
}

void Application::Update()
{
	for (auto m_item : m_items)
	{
		m_item->update(0.1);
	}
}