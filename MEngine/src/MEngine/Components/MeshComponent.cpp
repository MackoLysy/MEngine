#include "MeshComponent.h"
#include "MaterialComponent.h"
#include "../Helpers.h"
#include "../OpenGl/IndexBuffer.h"
#include "../OpenGl/VertexBuffer.h"
#include "../OpenGl/VertexArray.h"
#include "../OpenGl/Shader.h"
#include <Windows.h>
#include "../OpenGl/Shaders/Shaders.h"

MeshComponent::MeshComponent(MeshGenerator& mesh): m_type(0)
{
	setName("Mesh");
	m_va = std::make_shared<VertexArray>();
	m_vb = std::make_shared<VertexBuffer>(mesh.getVertexPointer(), sizeof(float) * mesh.getVertexCount());
	m_ib = std::make_shared<IndexBuffer>(mesh.getIndeciesPointer(), mesh.getIndeciesCount());
	m_layout = std::make_shared<VertexBufferLayout>();
	generateLayoutFromType(mesh.getType());
	m_va->AddBuffer(m_vb, m_layout);
}

MeshComponent::~MeshComponent()
{

}

void MeshComponent::preInit(std::unordered_map<std::string, std::shared_ptr<IComponent>>& components)
{
	auto it = components.find("Material");
	m_material = std::dynamic_pointer_cast<MaterialComponent>(it->second);
}

void MeshComponent::update()
{

}

void MeshComponent::draw()
{
	m_material->bind();
	m_va->Bind();
	m_ib->Bind();
	GLCall(glDrawElements(GL_TRIANGLES, m_ib->GetCount(), GL_UNSIGNED_INT, nullptr));
}

void MeshComponent::generateLayoutFromType(int type)
{
	m_layout = std::make_shared<VertexBufferLayout>();
	switch (type)
	{
	case 1:
		m_layout->Push<float>(3);
		m_layout->Push<float>(4);
		m_type = 1;
		break;
	case 2:
		m_layout->Push<float>(3);
		m_layout->Push<float>(2);
		m_type = 2;
	default:
		break;
	}
}
int MeshComponent::getType()
{
	return m_type;
}

