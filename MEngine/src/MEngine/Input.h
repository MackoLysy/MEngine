#pragma once
#include"Core.h"
#include <vector>
#include <memory>
struct GLFWwindow;
class InputComponent;

class MGINE_API Input
{
public:
	Input(GLFWwindow* window);
	~Input();
	
	static void  keyCallback(GLFWwindow* window, int key, int scannedCode, int action, int modes);
	void add(InputComponent* item);
	void remove(InputComponent *item);
private:
	void keyCallbackImp(int key, int scannedCode, int action, int modes);
	static Input* m_instance;
	static Input* getInstance();
	std::vector<InputComponent*> m_handlers;
};

