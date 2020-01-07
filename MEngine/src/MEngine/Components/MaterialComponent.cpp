#include "MaterialComponent.h"
#include "MeshComponent.h"
#include "../OpenGl/Shader.h"
#include "../OpenGl/Shaders/Shaders.h"
#include "../Application.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/trigonometric.hpp"

MaterialComponent::MaterialComponent()
{
	setName("Material");
	m_shader = std::make_shared<Shader>();
}

MaterialComponent::~MaterialComponent()
{

}

void MaterialComponent::preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
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

	it = components.find("Transform");
	m_transform = std::dynamic_pointer_cast<TransformComponent>(it->second);
	if (m_transform == nullptr)
	{
		return;
	}
}

void MaterialComponent::setDefaultShader()
{
	int type = m_mesh->getType();
	switch (type)
	{
	case 0:
	case 1:
		m_shader->Init(posColorVertexShader, posColorPixelShader);
		break;
	case 2:
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
	glm::mat4 Model = m_transform->getModelMatrix();
	m_shader->setUniforMat4f("u_Projection", Projection);
	m_shader->setUniforMat4f("u_Model", Model);
	m_shader->setUniforMat4f("u_View", View);
}

void MaterialComponent::draw()
{

}

void MaterialComponent::update()
{

}