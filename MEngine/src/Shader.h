#pragma once
#include <string>
#include <unordered_map>

#include "Helpers.h"
#include "glm/glm.hpp"

struct  ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader
{
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void UnBind() const;
	void setUniform4f(std::string name, float f1, float f2, float f3, float f4);
	void setUniform1i(std::string name, int i1);
	void setUniforMat4f(std::string name, const glm::mat4 matrix);
private:
	std::unordered_map <std::string, int> m_locationCache;
	unsigned int m_RendererID;
	std::string m_filePath;
	unsigned int GetUniformLocation(const std::string& name);
	ShaderProgramSource ParseShader(const std::string& source);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

};

