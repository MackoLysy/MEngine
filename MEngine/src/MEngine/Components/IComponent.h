#pragma once
#include <string>
#include "../Core.h"
#include <unordered_map>
#include <memory>

class IComponent
{
public:
	IComponent();
	virtual ~IComponent();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components) = 0;
	void setName(std::string& val) { n_name = val; }
	void setName(std::string val) { n_name = val; }
	const std::string& getName() const { return n_name; }
private:
	std::string n_name;

};

