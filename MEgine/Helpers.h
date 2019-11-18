#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if(!x)  __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLGetError());\

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}
bool GLGetError()
{
	while (GLenum error = glGetError())
	{
		std::cout << "[Error] " << error << std::endl;
		return false;
	}
	return true;
}