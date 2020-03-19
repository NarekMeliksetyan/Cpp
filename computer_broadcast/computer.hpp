#ifndef COMPUTER_HH
#define COMPUTER_HH

#include "head.hh"

class Computer : public Device {
public:
	Computer(size_t address) : Device(address) {
	}

	void find_servers(Call *call, Answer *answer) {
		call->insert(address_);
		for (auto conn : connections()) {
			if (call->have(conn->address())) {
				continue;
			}
			cout << " -> " << conn->address();
			call->insert(conn->address());
			conn->find_servers(call, answer);
		}
	}
};

#endif
