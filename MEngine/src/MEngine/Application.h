#pragma once
#include <iostream>
#include <memory>
#include <list>
#include "Core.h"
#include "Object.h"
#include "Input.h"
#include "../Vendor/glm/glm.hpp"

struct GLFWwindow;

class MGINE_API Application
{
public:
	Application();
	~Application();
	void addObject(Object*);
	void Run();
	static Application* getInstance();
	glm::mat4 getOrtoProjection();
	glm::mat4 getPerspectiveProjection();

private:
	static void resizeCallback(GLFWwindow* window, int width, int height);
	static Application* m_instance;
	void Init();
	void InitOjbects();
	std::unique_ptr<Input> m_input;
	GLFWwindow* m_window;
	std::list<Object*> m_items;
	glm::mat4 m_perspectiveProjection;
	glm::mat4 m_ortoProjection;
	void Draw();
	void Update();

};

