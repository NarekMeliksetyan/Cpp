#ifndef SERVER_HH
#define SERVER_HH

#include "head.hh"

class Server : public Device {
public:
	Server(string name, size_t address) : Device(address) {
		this->type = "server";
		this->name = name;
		this->address = address;
	}
};

#endif
