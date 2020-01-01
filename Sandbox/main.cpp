#include <iostream>
#include "MEgine.h"
#include <windows.h>

class Sandbox : public Application
{
public:
	Sandbox();
	~Sandbox();

private:
	Object *m_item;
	std::shared_ptr<MeshComponent> m_mesh;
};

Sandbox::Sandbox()
{
	unsigned int indecies[]
	{
		0, 1, 2,
		2, 3, 0
	};
	MeshGenerator meshGenerator = MeshGenerator::CreateMeshFromPosCol();
	Color color(1.0, 1.0, 1.0, 1.0);
	meshGenerator.push({ Pos(-0.5f, -0.5f, 0.0f), color });
	meshGenerator.push({ Pos(0.5f, -0.5f, 0.0f), color });
	meshGenerator.push({ Pos(0.5f,  0.5f, 0.0f), color });
	meshGenerator.push({ Pos(-0.5f,  0.5f, 0.0f), color });
	meshGenerator.pushIndecies(0);
	meshGenerator.pushIndecies(1);
	meshGenerator.pushIndecies(2);
	meshGenerator.pushIndecies(2);
	meshGenerator.pushIndecies(3);
	meshGenerator.pushIndecies(0);
	m_item = new Object;
	m_mesh = std::make_shared<MeshComponent>(meshGenerator);
	m_item->addComponent(m_mesh);
	this->addObject(m_item);
}

Sandbox ::~Sandbox()
{
}

int main() {
	std::cout << "Hello world!" << std::endl;
	Sandbox * app = new Sandbox();
	app->Run();
	delete app;
}