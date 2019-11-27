#pragma once
#include "Helpers.h"

class IndexBuffer
{
public:
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();
	void Bind() const;
	void UnBind();
	inline unsigned int GetCount() const { return m_count; }
private:
	unsigned int m_rendererId;
	unsigned int m_count;
	
};

