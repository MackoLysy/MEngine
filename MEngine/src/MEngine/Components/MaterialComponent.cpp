#include "MaterialComponent.h"
#include "MeshComponent.h"
#include "../OpenGl/Shader.h"
#include "../OpenGl/Shaders/Shaders.h"
#include "../Application.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/trigonometric.hpp"

MaterialComponent::MaterialComponent() : m_MeshType(0)
{
	setName("Material");
	m_shader = std::make_shared<Shader>();
}

MaterialComponent::~MaterialComponent()
{

}

void MaterialComponent::preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{
	setMeshComponent(components);
	setTextureComponent(components);
	setTransformComponent(components);
}

void MaterialComponent::setDefaultShader()
{
	m_MeshType = m_mesh->getType();
	switch (m_MeshType)
	{
	case 0:
		break;
	case 1:
		m_shader->Init(posColorVertexShader, posColorPixelShader);
		break;
	case 2:
		m_shader->Init(posTexVertexShader, posTexPixelShader);
		break;
	default:
		break;
	}
}

void MaterialComponent::bind()
{
	m_shader->Bind();
	auto Projection = Application::getInstance()->getOrtoProjection();
	glm::mat4 View = glm::lookAt(
		glm::vec3(0, 0, 0.1f), // Camera is at (4,3,3), in    World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	if (m_transform != nullptr)
	{
		glm::mat4 Model = m_transform->getModelMatrix();
		m_shader->setUniforMat4f("u_Model", Model);
	}
	m_shader->setUniforMat4f("u_Projection", Projection);
	m_shader->setUniforMat4f("u_View", View);
	bindTextureData();
}
void MaterialComponent::setMeshComponent(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{
	auto it = components.find("Mesh");
	m_mesh = std::dynamic_pointer_cast<MeshComponent>(it->second);
	if (m_mesh == nullptr)
	{
		return;
	}
	if (m_shader->isInitted())
	{
		setDefaultShader();
	}
}

void MaterialComponent::setTransformComponent(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{
	auto it = components.find("Transform");
	m_transform = std::dynamic_pointer_cast<TransformComponent>(it->second);
}

void MaterialComponent::setTextureComponent(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{
	if (m_MeshType == 2)
	{
		auto it = components.find("Texture");
		m_texture = std::dynamic_pointer_cast<TextureComponent>(it->second);
	}
}
void MaterialComponent::bindTextureData()
{
	if (m_MeshType == 2 && m_texture)
	{
		m_texture->bind(0);
		m_shader->setUniform1i("u_Texture", m_texture->getSlot());
	}
}
void MaterialComponent::draw()
{

}

void MaterialComponent::update()
{

}