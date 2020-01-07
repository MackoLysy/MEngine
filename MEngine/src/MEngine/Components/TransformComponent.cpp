#include "TransformComponent.h"
#include "../../Vendor/glm/gtx/transform.hpp"


TransformComponent::TransformComponent() : m_translation(1.0f, 1.0f, 1.0f), m_scale(1.0f, 1.0f, 1.0f), m_rotation(0.0f, 0.0f, 0.0f)
{
	setName("Transform");
}

TransformComponent::~TransformComponent()
{

}

void TransformComponent::update()
{

}

void TransformComponent::draw()
{

}

void TransformComponent::preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{

}

glm::vec3& TransformComponent::GetPosition()
{
	return m_translation;
}

glm::vec3& TransformComponent::GetRotation()
{
	return m_rotation;
}

glm::vec3& TransformComponent::GetScale()
{
	return m_scale;
}

glm::mat4 TransformComponent::getModelMatrix()
{
	return glm::translate(glm::mat4(1.0f), m_translation) * getRotationMatrix()* glm::scale(glm::mat4(1.0f), m_scale);
}

void TransformComponent::translate(float x, float y, float z)
{
	translate(glm::vec3(x, y, z));
}

void TransformComponent::translate(glm::vec3 vector)
{
	m_translation += vector;
}

void TransformComponent::scale(float x, float y, float z)
{
	scale(glm::vec3(x, y, z));
}

void TransformComponent::scale(glm::vec3 vector)
{
	m_scale *= vector;
}

void TransformComponent::rotate(float x, float y, float z)
{
	m_rotation = glm::vec3(x, y, z);
}

void TransformComponent::rotateX(float angle)
{
	m_rotation.x = angle;
}

void TransformComponent::rotateY(float angle)
{
	m_rotation.y = angle;
}

void TransformComponent::rotateZ(float angle)
{
	m_rotation.z = angle;
}

glm::mat4 TransformComponent::getRotationMatrix()
{
	return glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
}
