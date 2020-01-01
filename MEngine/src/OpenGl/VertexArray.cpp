#include "VertexArray.h"

#include "../Helpers.h"

VertexArray::VertexArray(): m_rendererId(0)
{
	GLCall(glGenVertexArrays(1, &m_rendererId));
	Bind();
}


VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_rendererId));
}

void VertexArray::AddBuffer(std::shared_ptr<VertexBuffer> vb, std::shared_ptr<VertexBufferLayout> layout)
{
	vb->Bind();
	const auto& elements = layout->GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto &element = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout->GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType((element.type));
	}
	
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_rendererId));
}

void VertexArray::UnBind()
{
	GLCall(glBindVertexArray(0));
}
