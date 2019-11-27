#pragma once
#include <iostream>
#include "Core.h"
__declspec(dllexport) void Print();

class MGINE_API Application
{
public:
	Application();
	void Run();
	~Application();
	void Test();
private:
	
};

