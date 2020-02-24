#pragma once
#include "../MEngine/Object.h"

#include "../MEngine/Components/MeshComponent.h"
#include "../MEngine/Components/MaterialComponent.h"
#include "../MEngine/Components/TransformComponent.h"
#include "../MEngine/Components/TextureComponent.h"

class MGINE_API Rect : public Object
{
public:
	Rect();
	Rect(std::string texture);
	Rect(Color color);
	~Rect();

private:
	void createDefaultMesh();
};
