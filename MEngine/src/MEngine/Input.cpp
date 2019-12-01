#include "Input.h"
#include <iostream>
#include "../Helpers.h"
#include "Components/InputComponent.h"

Input* Input::m_instance = nullptr;

Input::Input(GLFWwindow* window)
{
	m_instance = this;
}

Input::~Input()
{

}

void Input::keyCallback(GLFWwindow* window, int key, int scannedCode, int action, int modes)
{
	Input::getInstance()->keyCallbackImp(key, scannedCode, action, modes);
}

void Input::keyCallbackImp(int key, int scannedCode, int action, int modes)
{
	for (auto it = m_handlers.begin(); it!= m_handlers.end(); ++it)
	{
		if (*it != nullptr)
		{
			auto key = (*it)->GetKey();
			if (key.key == scannedCode && key.action == action && key.mode == modes)
			{
				(*it)->Notify();
			}
		}
	}
}

Input* Input::getInstance()
{
	return m_instance;
}

void Input::add(InputComponent* item)
{
	m_handlers.push_back(item);
}
void Input::remove(InputComponent *item)
{
	m_handlers.emplace_back(item);
}

