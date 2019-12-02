#ifndef DEVICE_HH
#define DEVICE_HH

#include "head.hh"

class Device {
protected:
	string	type_;			// type of device:
	string	name_;			// name of server (for server)
	size_t	calls_;			// number of calls (for switch)
	size_t	address_;		// address
	size_t	conn_nbr_;		// number of connections

	vector<Device*>	connections_;	// connections

public:
	Device(size_t address) {
		conn_nbr_ = 0;
		type_ = "device";
		address_ = address;
	}

	virtual ~Device() {
		connections_.clear();
	}

	virtual string type() {
		return type_;
	}

	virtual size_t address() {
		return address_;
	}

	virtual size_t conn_nbr() {
		return conn_nbr_;
	}

	virtual vector<Device*> connections() {
		return connections_;
	}

	virtual string name() {
		return name_;
	}

	virtual void add_call() {
		calls_++;
	}

	virtual void connect(Device *devc) {
 		connections_.push_back(devc);
		conn_nbr_++;
	}

	virtual bool connected(Device *devc) {
		for (auto conn : connections_)
			if (conn->address() == devc->address()) {
				return true;
			}
		return false;
	}

	virtual void find_servers(Call *call, Answer *answer) {
		call->insert(address_);
		for (auto conn : connections()) {
			if (call->have(conn->address())) {
				continue;
			}
			call->insert(conn->address());
			if (conn->type() == "server") {
				answer->insert(conn->name());
				cout << " -> " << conn->name();
			} else if (conn->type() == "computer") {
				cout << " -> " << conn->address();
				conn->find_servers(call, answer);
			} else if (conn->type() == "switch") {
				conn->add_call();
				cout << " -> " << conn->address();
				conn->find_servers(call, answer);
			}
		}
	}
};

#endif
