#pragma once
#include "IComponent.h"
#include <vector>
#include <memory>
#include "../Core.h"
#include "../Vertex.h"
#include "../Mesh/MeshGenerator.h"

class IndexBuffer;
class VertexBuffer;
class VertexBufferLayout;
class VertexArray;
class Shader;

class MGINE_API MeshComponent : public IComponent
{
public:
	MeshComponent(MeshGenerator& mesh);
	~MeshComponent();
	void update() override;
	void draw() override;
private:
	void generateLayoutFromType(int type);
	std::shared_ptr<VertexArray> m_va;
	std::shared_ptr<VertexBuffer> m_vb;
	std::shared_ptr<IndexBuffer> m_ib;
	std::shared_ptr<VertexBufferLayout> m_layout;
	std::shared_ptr<Shader> m_shader;
};
