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

class MGINE_API InputComponent :public IComponent
{
public:
	InputComponent(KeyEvent key);
	InputComponent(int key, int action, int mode);
	~InputComponent();
	void Notify();
	KeyEvent GetKey();
	void update() override;
	void draw() override;
private:
	KeyEvent m_key;
};
