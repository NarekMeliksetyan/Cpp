#ifndef SERVER_HH
#define SERVER_HH

#include "head.hh"

class Server : public Device {
public:
	Server(string name, size_t address) : Device(address) {
		type_ = "server";
		name_ = name;
		address_ = address;
	}
};

#endif
