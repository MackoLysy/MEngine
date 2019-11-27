#include "Helpers.h"

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