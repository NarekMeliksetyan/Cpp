#ifndef COMPUTER_HH
#define COMPUTER_HH

#include "head.hh"

class Computer : public Device {
private:
	set<string>	servers;	// available servers

public:
	Computer(size_t address) : Device(address) {
		this->type = "computer";
	}

	void add_servers(set<string> servers) {
		this->servers = servers;
	}

	set<string> get_servers() {
		return servers;
	}
};

#endif
