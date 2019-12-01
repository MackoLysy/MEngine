#pragma once
#include <functional>
#include <vector>
#include <memory>

#include "Eventhanlder.h"
#include "../Core.h"

class MGINE_API EventHandler;
class Event {
	std::vector<std::unique_ptr<EventHandler>> handlers;

	void NotifyHandlers();
public:
	void AddHandler(const EventHandler &handler);

	void RemoveHandler(const EventHandler &handler);

	void operator()();

	Event &operator+=(const EventHandler &handler);
	Event &operator+=(const EventHandler::Func &handler);
	Event &operator-=(const EventHandler &handler);
};