#include <iostream>
#include "MEgine.h"

class Sandbox: Application
{
public:
	Sandbox ();
	~Sandbox ();

private:

};

Sandbox ::Sandbox ()
{
}

Sandbox ::~Sandbox ()
{
}

int main()
{
	std::cout << "Hello world!" << std::endl;
	Application * app = new Application();
	app->Run();
	delete app;
}