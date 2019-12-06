#ifndef SERVER_HH
#define SERVER_HH

#include "head.hh"

class Server : public Device {
private:
	string	name_;			// name of server

public:
	Server(string name, size_t address) : Device(address) {
		name_ = name;
		address_ = address;
	}

	string name() {
		return name_;
	}

	void find_servers(Call *call, Answer *answer) {
		call->insert(address_);
		answer->insert(name_);
		cout << " -> " << name_;
	}
};

#endif
