#pragma once
#include"IComponent.h"
#include "../Core.h"
#include "../Event/Eventhanlder.h"

struct KeyEvent
{
	int key;
	int action;
	int mode;
	EventHandler handler;
};

class InputComponent :public IComponent
{
public:
	InputComponent(KeyEvent key);
	InputComponent(int key, int action, int mode);
	~InputComponent();
	void Notify();
	KeyEvent GetKey();
private:
	KeyEvent m_key;
};
