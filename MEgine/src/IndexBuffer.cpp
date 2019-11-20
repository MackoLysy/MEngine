#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count): m_count(count)
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	GLCall(glGenBuffers(1, &m_rendererId));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
	GLCall(glBufferData(GL_ARRAY_BUFFER, count *sizeof(GLuint), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_rendererId));
}

void IndexBuffer::Bind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererId));
}

void IndexBuffer::UnBind()
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}