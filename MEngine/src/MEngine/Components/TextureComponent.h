#pragma once
#include "IComponent.h"
#include "../Core.h"

class Texture;

class MGINE_API TextureComponent : public IComponent
{
public:
	TextureComponent();
	TextureComponent(std::string path);
	~TextureComponent();
	void update() override;
	void draw() override;
	void bind(unsigned int slot = 0);
	unsigned int getSlot() const;
	void preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components) override;
private:
	std::shared_ptr<Texture> m_texture;
};

