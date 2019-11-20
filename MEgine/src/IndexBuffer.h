#pragma once
#include "Renderer.h"

class IndexBuffer
{
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();
	void Bind();
	void UnBind();
private:
	unsigned int m_rendererId;
	unsigned int m_count;
	inline unsigned int GetCount() const { return m_count; }
};

