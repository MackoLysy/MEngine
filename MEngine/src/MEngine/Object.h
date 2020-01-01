#pragma once
#include <unordered_map>
#include <memory>

#include "Components/IComponent.h"
#include "Core.h"

class MGINE_API Object
{
public:
	Object();
	virtual ~Object();
	void draw();
	void update(float dt);
	void addComponent(std::shared_ptr<IComponent> component);
	void removeComponent(std::shared_ptr<IComponent> component);
	std::shared_ptr<IComponent> getComponent(std::string name);
private:
	std::unordered_map<std::string, std::shared_ptr<IComponent>> m_components;
	//std:: std::shared_ptr<IComponent>> m_components;
};

