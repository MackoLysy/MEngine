#pragma once
#include <functional>
#include <iostream>
#include "../Core.h"

class MGINE_API EventHandler {
public:
	using Func = std::function<void()>;

private:
	Func _func;

public:
	int id;
	static int counter;

	EventHandler() : id{ 0 } {
	}

	EventHandler(const Func &func);

	void operator()();
	void operator=(const EventHandler &func);
	bool operator==(const EventHandler &del);
	bool operator!=(nullptr_t);
};
