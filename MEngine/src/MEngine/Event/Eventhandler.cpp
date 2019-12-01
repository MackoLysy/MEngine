#include "Eventhanlder.h"

int EventHandler::counter = 0;

EventHandler::EventHandler(const Func &func) : _func{ func } {
	this->id = ++EventHandler::counter;
}

void EventHandler::operator()() {
	this->_func();
}


void EventHandler::operator=(const EventHandler &func) {
	if (this->_func == nullptr) {
		this->_func = func;
		this->id = ++EventHandler::counter;
	}
	else {
		// Throw as exception or just log it out.
		std::cerr << "Nope!" << std::endl;
	}
}

bool EventHandler::operator==(const EventHandler &del) {
	return this->id == del.id;
}
bool EventHandler::operator!=(nullptr_t) {
	return this->_func != nullptr;
}