#include <iostream>
#include "MEngine.h"

class Sandbox : public Application
{
public:
	Sandbox();
	~Sandbox();

private:
	Object *m_item;
	Object *m_item2;
};

Sandbox::Sandbox()
{
	unsigned int indecies[]
	{
		0, 1, 2,
		2, 3, 0
	};
	MeshGenerator meshGenerator = MeshGenerator::CreateMeshFromPosTex();
	Color colorRed(1.0, 0.0, 0.0, 1.0);
	Color colorGreen(0.0, 1.0, .0, 1.0);
	Color colorBlue(0.0, 0.0, 1.0, 1.0);
	Color colorRest(0.0, 1.0, 1.0, 1.0);

	/*meshGenerator.push({ Pos(-0.5f, -0.5f, 0.0f), colorRed });
	meshGenerator.push({ Pos(0.5f, -0.5f, 0.0f), colorGreen });
	meshGenerator.push({ Pos(0.5f,  0.5f, 0.0f), colorBlue });
	meshGenerator.push({ Pos(-0.5f,  0.5f, 0.0f), colorRest });*/

	meshGenerator.push({ Pos(0.0f, 0.0f, 0.0f), TexCord(0.0f,0.0f) });
	meshGenerator.push({ Pos(0.0f, 1.0f, 0.0f), TexCord(0.0f,1.0f) });
	meshGenerator.push({ Pos(1.0f, 1.0f, 0.0f), TexCord(1.0f,1.0f) });
	meshGenerator.push({ Pos(1.0f, 0.0f, 0.0f), TexCord(1.0f,0.0f) });

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
	std::shared_ptr<TextureComponent> m_texture;
	m_texture = std::make_shared<TextureComponent>("res/images.png");
	m_transform->translate(400.0f, 0.0f, 0.0f);
	m_transform->scale(300.0f, 300.0f, 0.0f);
	m_transform->rotateZ(45.0f);
	m_item->addComponent(m_mesh);
	m_item->addComponent(m_material);
	m_item->addComponent(m_transform);
	m_item->addComponent(m_texture);
	m_item2 = new Object;

	std::shared_ptr<TransformComponent> m_transform2;
	std::shared_ptr<MaterialComponent> m_material2;
	std::shared_ptr<MeshComponent> m_mesh2;
	m_mesh2 = std::make_shared<MeshComponent>(meshGenerator);
	m_material2 = std::make_shared<MaterialComponent>();
	m_transform2 = std::make_shared<TransformComponent>();
	m_item2->addComponent(m_mesh2);
	m_item2->addComponent(m_material2);
	m_item2->addComponent(m_transform2);
	m_item2->addComponent(m_texture);
	m_transform2->scale(300.0f, 300.0f, 0.0f);
	m_transform2->translate(200.0f, 500.0f, 0.0f);
	addLayer(0, Layer());
	auto layer = getLayer(0);
	layer->add(m_item);
	layer->add(m_item2);
}

Sandbox ::~Sandbox()
{

}

int main() {
	std::cout << "Hello world!" << std::endl;
	Sandbox * app = new Sandbox();
	app->run();
	delete app;
}