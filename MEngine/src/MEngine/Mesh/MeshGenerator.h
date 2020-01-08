#pragma once
#include "../Core.h"
#include "../Vertex.h"
#include <vector>
#include <iostream>

class MGINE_API MeshGenerator
{
public:
	static MeshGenerator CreateMeshFromPosCol();
	static MeshGenerator CreateMeshFromPosTex();
	~MeshGenerator();
	void push(PosColVertex elemet);
	void push(PosTexVertex elemet);
	void pushIndecies(unsigned int val);
	int getVertexCount() const;
	int getIndeciesCount() const;
	float* getVertexPointer();
	unsigned int* getIndeciesPointer();
	int getType() const;
private:
	MeshGenerator();
	enum Type {
		NONE = 0,
		POSCOL,
		POSTEX,
	};
	Type m_type;
	std::vector<unsigned int> m_indecies;
	std::vector<float> m_vertices;
};

