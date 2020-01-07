#include <iostream>
#include "MEngine.h"

class Sandbox : public Application
{
public:
	Sandbox();
	~Sandbox();

private:
	Object *m_item;
	
};

Sandbox::Sandbox()
{
	unsigned int indecies[]
	{
		0, 1, 2,
		2, 3, 0
	};
	MeshGenerator meshGenerator = MeshGenerator::CreateMeshFromPosCol();
	Color colorRed(1.0, 0.0, 0.0, 1.0);
	Color colorGreen(0.0, 1.0, .0, 1.0);
	Color colorBlue(0.0, 0.0, 1.0, 1.0);
	Color colorRest(0.0, 1.0, 1.0, 1.0);

	/*meshGenerator.push({ Pos(-0.5f, -0.5f, 0.0f), colorRed });
	meshGenerator.push({ Pos(0.5f, -0.5f, 0.0f), colorGreen });
	meshGenerator.push({ Pos(0.5f,  0.5f, 0.0f), colorBlue });
	meshGenerator.push({ Pos(-0.5f,  0.5f, 0.0f), colorRest });*/

	meshGenerator.push({ Pos(0.0f, 0.0f, 0.0f), colorRed });
	meshGenerator.push({ Pos(0.0f, 1.0f, 0.0f), colorGreen });
	meshGenerator.push({ Pos(1.0f, 1.0f, 0.0f), colorBlue });
	meshGenerator.push({ Pos(1.0f, 0.0f, 0.0f), colorRest });

	/*meshGenerator.push({ Pos(100.0f, 100.0f, 0.0f), colorRed });
	meshGenerator.push({ Pos(100.0f, 200.0f, 0.0f), colorGreen });
	meshGenerator.push({ Pos(200.0f, 200.0f, 0.0f), colorBlue });
	meshGenerator.push({ Pos(200.0f, 100.0f, 0.0f), colorRest });*/

	meshGenerator.pushIndecies(0);
	meshGenerator.pushIndecies(1);
	meshGenerator.pushIndecies(2);
	meshGenerator.pushIndecies(2);
	meshGenerator.pushIndecies(3);
	meshGenerator.pushIndecies(0);
	m_item = new Object;
	std::shared_ptr<MeshComponent> m_mesh;
	m_mesh = std::make_shared<MeshComponent>(meshGenerator);
	std::shared_ptr<MaterialComponent> m_material;
	m_material = std::make_shared<MaterialComponent>();
	std::shared_ptr<TransformComponent> m_transform;
	m_transform = std::make_shared<TransformComponent>();
	m_transform->translate(400.0f, 20.0f, 0.0f);
	m_transform->scale(100.0f, 100.0f, 0.0f);
	m_transform->rotateZ(30.0f);
	m_item->addComponent(m_mesh);
	m_item->addComponent(m_material);
	m_item->addComponent(m_transform);
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