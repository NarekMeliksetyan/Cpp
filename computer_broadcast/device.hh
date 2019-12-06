#ifndef DEVICE_HH
#define DEVICE_HH

#include "head.hh"

class Device {
protected:
	size_t	address_;		// address
	size_t	conn_nbr_;		// number of connections

	vector<Device*>	connections_;	// connections

public:
	Device(size_t address) {
		conn_nbr_ = 0;
		address_ = address;
	}

	virtual ~Device() {
		connections_.clear();
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

	virtual void find_servers(Call *call, Answer *answer) {}
};

#endif
