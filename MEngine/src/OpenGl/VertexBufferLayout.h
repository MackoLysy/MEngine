#pragma once
#include <vector>
#include "GL/glew.h"

#include "../Helpers.h"
#include "../MEngine/Vertex.h"

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:
			return 4;
		case GL_UNSIGNED_INT:
			return 4;
		case GL_UNSIGNED_BYTE:
			return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout
{
public:
	VertexBufferLayout();
	~VertexBufferLayout();

	// void Push(unsigned int count)
	// {
	// 	static_assert(false);
	// }

	void PushFloat(unsigned int count)
	{
		m_Elements.push_back({GL_FLOAT,
							  count,
							  GL_FALSE});
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	void PushPos(unsigned int count)
	{
	}

	void PushColor(unsigned int count)
	{
	}

	void PushUnsignedInt(unsigned int count)
	{
		m_Elements.push_back({GL_UNSIGNED_INT,
							  count,
							  GL_FALSE});
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	void PushUnsignedChar(unsigned int count)
	{
		m_Elements.push_back({GL_UNSIGNED_BYTE,
							  count,
							  GL_TRUE});
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_BYTE);
	}

	inline unsigned int GetStride() const { return m_Stride; }
	inline std::vector<VertexBufferElement> &GetElements() { return m_Elements; }

private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
};
