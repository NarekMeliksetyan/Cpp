#ifndef COMPUTER_HH
#define COMPUTER_HH

#include "head.hh"

class Computer : public Device {
private:
	set<string>	servers_;	// available servers

public:
	Computer(size_t address) : Device(address) {
		type_ = "computer";
	}

	void add_servers(set<string> servers) {
		servers_ = servers;
	}

	set<string> servers() {
		return servers_;
	}
};

#endif
