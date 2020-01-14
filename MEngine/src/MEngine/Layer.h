#pragma once
#include "Core.h"
#include "Object.h"
#include <list>
#include <memory>

class MGINE_API Layer
{
public:
	Layer();
	~Layer();
	void draw();
	void initObject();
	void add(Object* item);
private:
	std::list<Object*> m_items;
	//std::list<std::shared_ptr<Object>> m_items;
};

