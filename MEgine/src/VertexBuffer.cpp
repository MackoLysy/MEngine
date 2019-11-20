#include "VertexBuffer.h"



VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &m_rendererId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}


VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_rendererId));
}

void VertexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
}
void VertexBuffer::Unbind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
