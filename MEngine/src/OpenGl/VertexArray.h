#pragma once
#include <memory>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	//void AddBuffer(VertexBuffer& vb, VertexBufferLayout& layout);
	void AddBuffer(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<VertexBufferLayout> layout);
	void Bind() const;
	void UnBind();
private:
	unsigned int m_rendererId;

};

