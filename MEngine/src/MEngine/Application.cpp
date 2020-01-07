#include "Application.h"
#include "../Helpers.h"
#include "glm/gtc/matrix_transform.hpp"

Application* Application::m_instance = nullptr;

Application::Application()
{
	m_instance = this;
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
	m_ortoProjection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);
	m_perspectiveProjection = glm::perspective(45.0f, (float)800 / (float)600, 0.1f, 160.0f);
	glfwMakeContextCurrent(m_window);
	m_input = std::make_unique<Input>(m_window);
	glfwSetKeyCallback(m_window, Input::keyCallback);
	glfwSetWindowSizeCallback(m_window, &Application::resizeCallback);
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
	InitOjbects();
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

Application* Application::getInstance()
{
	return m_instance;
}

glm::mat4 Application::getOrtoProjection()
{
	return m_ortoProjection;
}

glm::mat4 Application::getPerspectiveProjection()
{
	return m_perspectiveProjection;
}

void Application::resizeCallback(GLFWwindow* window, int width, int height)
{
	m_instance->m_ortoProjection = glm::ortho(0.0f, (float)width, 0.0f, float(height), -1.0f, 1.0f);
	m_instance->m_perspectiveProjection = glm::perspective(45.0f, (float)width / (float)height, 0.1f, 160.0f);
	glViewport(0, 0, width, height);
}

Application::~Application()
{

}

void Print()
{
	std::cout << "Hello World!" << std::endl;
}
void Application::InitOjbects()
{
	for (auto item : m_items)
	{
		item->preInitComponents();
	}
}
void Application::addObject(Object* item)
{
	m_items.push_back(item);
}
void Application::Draw()
{
	for (auto m_item : m_items)
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