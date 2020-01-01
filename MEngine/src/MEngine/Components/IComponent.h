#pragma once
#include <string>

class IComponent
{
public:
	IComponent();
	virtual ~IComponent();
	virtual void update() = 0;
	virtual void draw() = 0;
	void setName(std::string& val) { n_name = val; }
	void setName(std::string val) { n_name = val; }
	const std::string& getName() const { return n_name; }
private:
	std::string n_name;

};

