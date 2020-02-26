#pragma once
#include <iostream>
#include <GL/glew.h>

#include <GLFW/glfw3.h>

void GLClearError();
bool GLGetError();
#ifdef _PLATFORM_WINDOWS
#define ASSERT(x) \
	if (!x)       \
		__debugbreak();
#else
#define ASSERT(x) \
	if (!x)       \
		std::cout << "Nie dziala!" << std::endl;
		// __asm__("int $03");
#endif

#define GLCall(x)   \
	GLClearError(); \
	x;              \
	ASSERT(GLGetError());
