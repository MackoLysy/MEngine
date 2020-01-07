#include "Object.h"

Object::Object()
{

}


Object::~Object()
{

}

void Object::draw()
{
	for (auto n : m_components)
	{
		n.second->draw();
	}
}

void Object::update(float dt)
{
	for (auto n : m_components)
	{
		n.second->update();
	}
}

void Object::preInitComponents()
{
	for (auto n : m_components)
	{
		n.second->preInit(m_components);
	}
}

void Object::addComponent(std::shared_ptr<IComponent> component)
{
	m_components[component->getName()] = component;
}
void Object::removeComponent(std::shared_ptr<IComponent> component)
{
	m_components.erase(component->getName());
}

std::shared_ptr<IComponent> Object::getComponent(std::string name)
{
	auto it = m_components.find(name);
	return it->second;
}
