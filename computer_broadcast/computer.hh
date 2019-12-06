#ifndef COMPUTER_HH
#define COMPUTER_HH

#include "head.hh"

class Computer : public Device {
private:
	set<string>	servers_;	// available servers

public:
	Computer(size_t address) : Device(address) {
	}

	void add_servers(set<string> servers) {
		servers_ = servers;
	}

	void find_servers(Call *call, Answer *answer) {
		call->insert(address_);
		cout << " -> " << address_;
		for (auto conn : connections()) {
			if (call->have(conn->address())) {
				continue;
			}
			call->insert(conn->address());
			conn->find_servers(call, answer);
		}
	}

	set<string> servers() {
		return servers_;
	}
};

#endif
