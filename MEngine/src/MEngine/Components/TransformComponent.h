#pragma once
#include "IComponent.h"
#include "../../Vendor/glm/glm.hpp"

class MGINE_API TransformComponent : public IComponent
{

public:
	TransformComponent();
	~TransformComponent();
	void update() override;
	void draw() override;
	void preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components) override;
	glm::vec3& GetPosition();
	glm::vec3& GetRotation();
	glm::vec3& GetScale();
	glm::mat4 getModelMatrix();
	void translate(float x, float y, float z);
	void translate(glm::vec3 vector);
	void scale(float x, float y, float z);
	void scale(glm::vec3 vector);
	void rotate(float angle, float y, float z);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

private:
	glm::mat4 getRotationMatrix();
	glm::mat4 m_rotationMatrix;
	glm::vec3 m_translation;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
};

