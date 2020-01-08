#include "TextureComponent.h"
#include "../OpenGl/Texture.h"

TextureComponent::TextureComponent()
{
	setName("Texture");
}

TextureComponent::TextureComponent(std::string path)
{
	setName("Texture");
	m_texture = std::make_shared<Texture>(path);
}

void TextureComponent::bind(unsigned int slot)
{
	m_texture->Bind(slot);
}

unsigned int TextureComponent::getSlot() const
{
	return m_texture->getSlot();
}

TextureComponent::~TextureComponent()
{

}


void TextureComponent::update()
{

}

void TextureComponent::draw()
{

}

void TextureComponent::preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{

}