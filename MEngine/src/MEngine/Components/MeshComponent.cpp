#include "MeshComponent.h"
#include "../Helpers.h"
#include "../OpenGl/IndexBuffer.h"
#include "../OpenGl/VertexBuffer.h"
#include "../OpenGl/VertexArray.h"
#include "../Shader.h"
#include <Windows.h>

MeshComponent::MeshComponent(MeshGenerator& mesh)
{
	setName("Mesh");
	m_va = std::make_shared<VertexArray>();
	m_vb = std::make_shared<VertexBuffer>(mesh.getVertexPointer(), sizeof(float) * mesh.getVertexCount());
	m_ib = std::make_shared<IndexBuffer>(mesh.getIndeciesPointer(), mesh.getIndeciesCount());
	m_layout = std::make_shared<VertexBufferLayout>();
	generateLayoutFromType(mesh.getType());
	m_va->AddBuffer(m_vb, m_layout);
	m_shader = std::make_shared<Shader>("res/shader/Basic.Shader");
}

void MeshComponent::update()
{

}

void MeshComponent::draw()
{
	m_shader->Bind();
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
		break;
	case 2:
		m_layout->Push<float>(3);
		m_layout->Push<float>(2);
	default:
		break;
	}
}

MeshComponent::~MeshComponent()
{

}
