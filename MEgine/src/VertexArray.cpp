#include "VertexArray.h"

#include "Renderer.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_rendererId));
	Bind();
}


VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_rendererId));
}

void VertexArray::AddBuffer(VertexBuffer& vb, VertexBufferLayout& layout)
{
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto &element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType((element.type));
	}
	
}

void VertexArray::Bind()
{
	GLCall(glBindVertexArray(m_rendererId));
}

void VertexArray::UnBind()
{
	GLCall(glBindVertexArray(0));
}
