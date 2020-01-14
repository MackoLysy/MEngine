#include "Layer.h"

Layer::Layer()
{
}

Layer::~Layer()
{
}

void Layer::draw()
{
	for (auto item : m_items)
	{
		item->draw();
	}
}

void Layer::add(Object * object)
{
	m_items.push_back(object);
}

void Layer::initObject()
{
	for (auto item : m_items)
	{
		item->preInitComponents();
	}
}