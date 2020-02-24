#include "Rect.h"

Rect::Rect()
{
}

Rect::Rect(std::string texture)
{
}

Rect::Rect(Color color)
{
}

Rect::~Rect()
{
}

void Rect::createDefaultMesh()
{
	auto mesh = MeshGenerator::CreateMeshFromPosCol();

}