#ifndef DEVICE_HH
#define DEVICE_HH

#include "head.hh"

class Device {
protected:
	string	type;			// type of device:
	string	name;			// name of server (for server)
	size_t	calls;			// number of calls (for switch)
	size_t	address;		// address
	size_t	conn_nbr;		// number of connections

	vector<Device*>	connections;	// connections

public:
	Device(size_t address) {
		this->conn_nbr = 0;
		this->type = "device";
		this->address = address;
	}

	virtual ~Device() {
		connections.clear();
	}

	virtual string get_type() {
		return type;
	}

	virtual size_t get_address() {
		return address;
	}

	virtual size_t get_conn_nbr() {
		return conn_nbr;
	}

	virtual vector<Device*> get_connections() {
		return connections;
	}

	virtual string get_name() {
		return name;
	}

	virtual void add_call() {
		calls++;
	}

	virtual void connect(Device *devc) {
 		connections.push_back(devc);
		conn_nbr++;
	}

	virtual bool connected(Device *devc) {
		for (auto conn : connections)
			if (conn->get_address() == devc->get_address()) {
				return true;
			}
		return false;
	}

	virtual void find_servers(Call *call, Answer *answer) {
		call->insert(address);
		for (auto conn : get_connections()) {
			if (call->have(conn->get_address())) {
				continue;
			}
			call->insert(conn->get_address());
			if (conn->get_type() == "server") {
				answer->insert(conn->get_name());
				cout << " -> " << conn->get_name();
			} else if (conn->get_type() == "computer") {
				cout << " -> " << conn->get_address();
				conn->find_servers(call, answer);
			} else if (conn->get_type() == "switch") {
				conn->add_call();
				cout << " -> " << conn->get_address();
				conn->find_servers(call, answer);
			}
		}
	}
};

#endif
