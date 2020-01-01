#include "InputComponent.h"



InputComponent::InputComponent(KeyEvent key) : m_key(key)
{

}
InputComponent::InputComponent(int key, int action, int mode)
{
	m_key.key = key;
	m_key.action = action;
	m_key.mode = mode;
}

InputComponent::~InputComponent()
{

}

void InputComponent::Notify()
{
	int a = 12;
}

KeyEvent InputComponent::GetKey()
{
	return m_key;
}

void InputComponent::update() {}
void InputComponent::draw() {}