#pragma once
#include <iostream>
#include <GL/glew.h>

#include <GLFW/glfw3.h>

void GLClearError();
bool GLGetError();

#define ASSERT(x) if(!x)  __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLGetError());\

