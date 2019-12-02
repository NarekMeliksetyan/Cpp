#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "head.hh"

class Switch : public Device {
public:
	Switch(size_t address) : Device(address) {
		this->type = "switch";
	}

	virtual size_t calls() {
		return calls_;
	}
};

#endif
 
