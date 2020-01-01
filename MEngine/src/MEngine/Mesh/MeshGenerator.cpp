#include "MeshGenerator.h"



MeshGenerator::MeshGenerator()
{
	m_vertices.clear();
	m_indecies.clear();
}


MeshGenerator::~MeshGenerator()
{

}

void MeshGenerator::push(PosColVertex elemet)
{
	m_vertices.push_back(elemet.m_pos.m_x);
	m_vertices.push_back(elemet.m_pos.m_y);
	m_vertices.push_back(elemet.m_pos.m_z);

	m_vertices.push_back(elemet.m_color.m_r);
	m_vertices.push_back(elemet.m_color.m_g);
	m_vertices.push_back(elemet.m_color.m_b);
	m_vertices.push_back(elemet.m_color.m_a);
}
void MeshGenerator::push(PosTexVertex elemet)
{
	m_vertices.push_back(elemet.m_pos.m_x);
	m_vertices.push_back(elemet.m_pos.m_y);
	m_vertices.push_back(elemet.m_pos.m_z);

	m_vertices.push_back(elemet.m_texCoord.m_x);
	m_vertices.push_back(elemet.m_texCoord.m_y);
}
void MeshGenerator::pushIndecies(unsigned int val)
{
	m_indecies.push_back(val);
}
int MeshGenerator::getVertexCount() const
{
	return m_vertices.size();
}
int MeshGenerator::getIndeciesCount() const
{
	return m_indecies.size();
}

unsigned int* MeshGenerator::getIndeciesPointer()
{
	return &m_indecies[0];
}
float* MeshGenerator::getVertexPointer()
{
	return &m_vertices[0];
}

MeshGenerator MeshGenerator::CreateMeshFromPosCol()
{
	MeshGenerator gen;
	gen.m_type = POSCOL;
	return gen;
}

int MeshGenerator::getType() const
{
	return static_cast<int>(m_type);
}