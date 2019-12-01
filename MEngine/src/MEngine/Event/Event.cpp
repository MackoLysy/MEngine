#include "Event.h"


void Event::NotifyHandlers() {
	std::vector<std::unique_ptr<EventHandler>>::iterator func = this->handlers.begin();
	for (; func != this->handlers.end(); ++func) {
		if (*func != nullptr && (*func)->id != 0) {
			(*(*func))();
		}
	}
}


void Event::AddHandler(const EventHandler &handler) {
	this->handlers.push_back(std::unique_ptr<EventHandler>(new EventHandler{ handler }));
}

void Event::RemoveHandler(const EventHandler &handler) {
	std::vector<std::unique_ptr<EventHandler>>::iterator to_remove = this->handlers.begin();
	for (; to_remove != this->handlers.end(); ++to_remove) {
		if (*(*to_remove) == handler) {
			this->handlers.erase(to_remove);
			break;
		}
	}
}

void Event::operator()() {
	this->NotifyHandlers();
}

Event &Event::operator+=(const EventHandler &handler) {
	this->AddHandler(handler);

	return *this;
}

Event &Event::operator+=(const EventHandler::Func &handler) {
	this->AddHandler(EventHandler{ handler });

	return *this;
}

Event &Event::operator-=(const EventHandler &handler) {
	this->RemoveHandler(handler);

	return *this;
}