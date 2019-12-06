#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "head.hh"

class Switch : public Device {
private:
	size_t	calls_;			// number of calls

public:
	Switch(size_t address) : Device(address) {
	}

	virtual size_t calls() {
		return calls_;
	}

	void add_call() {
		calls_++;
	}

	virtual void find_servers(Call *call, Answer *answer) {
		call->insert(address_);
		add_call();
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
 
