#pragma once
#include <iostream>
#include <memory>
#include <list>
#include "Core.h"
#include "Object.h"
#include "Input.h"
#include "Layer.h"
#include "../Vendor/glm/glm.hpp"

struct GLFWwindow;

class MGINE_API Application
{
public:
	Application();
	~Application();
	void addObject(Object*);
	std::shared_ptr<Layer> getLayer(int number);
	void addLayer(int number, Layer layer);
	void run();
	static Application* getInstance();
	glm::mat4 getOrtoProjection();
	glm::mat4 getPerspectiveProjection();

private:
	static void resizeCallback(GLFWwindow* window, int width, int height);
	static Application* m_instance;
	void init();
	void initOjbects();
	std::unique_ptr<Input> m_input;
	GLFWwindow* m_window;
	std::list<Object*> m_items;
	std::unordered_map<int, std::shared_ptr<Layer>> m_layers;
	glm::mat4 m_perspectiveProjection;
	glm::mat4 m_ortoProjection;
	void draw();
	void update();

};

