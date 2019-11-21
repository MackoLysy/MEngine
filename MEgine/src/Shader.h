#pragma once
#include <string>

class Shader
{
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind();
	void UnBind();

private:
	unsigned int m_RendererID;
};

