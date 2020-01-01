#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "OpenGl/VertexArray.h"
#include "OpenGl/IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:

	Renderer();
	~Renderer();
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void Clear();
};

