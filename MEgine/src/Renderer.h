#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if(!x)  __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLGetError());\

void GLClearError();
bool GLGetError();

class Renderer
{
public:
	Renderer();
	~Renderer();
};

