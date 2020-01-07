#pragma once
#include "IComponent.h"
#include "../Core.h"


class Shader;
class MeshComponent;
class TransformComponent;

class MGINE_API MaterialComponent: public IComponent
{
public:
	MaterialComponent();
	~MaterialComponent();
	void preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components) override;
	void bind();
	void update() override;
	void draw() override;
private:
	void setDefaultShader();
	std::shared_ptr<Shader> m_shader;
	std::shared_ptr<MeshComponent> m_mesh;
	std::shared_ptr<TransformComponent> m_transform;
};

