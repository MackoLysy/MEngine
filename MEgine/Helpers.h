#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define ASSERT(x) if(!x)  __debugbreak();
#define GLCall(x) GLClearColor();\
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