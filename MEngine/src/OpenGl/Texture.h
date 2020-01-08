#pragma once
#include "../Helpers.h"


class Texture
{
public:
	Texture(const std::string& filePath);
	~Texture();
	void Bind(unsigned int slot = 0);
	void Unbind();
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
	unsigned int getSlot() const { return m_slot; }
private:
	unsigned int m_slot;
	unsigned int m_RednererId;
	std::string m_filePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;

};

