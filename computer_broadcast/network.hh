#ifndef NETW0RK_HH
#define NETW0RK_HH

#include "head.hh"

class Network : public Device {
private:
	size_t		comp_nbr_;			// number of computers
	size_t		switch_nbr_;		// number of switches
	size_t		serv_nbr_;			// number of srvers
	size_t		comp_max_conn_;		// max number of computer connections
	size_t		swtch_max_conn_;	// max number of switch connections
	size_t		serv_max_conn_;		// max number of server connections

	Call		*call_;				// call to server
	Answer		*answer_;			// answer to call

	set<int>			checked_;		// checked addresses during connection checking
	vector<Computer*>	computers_;		// computers in the network
	vector<Switch*>		switches_;		// swtiches in the network
	vector<Server*>		servers_;		// servers in the network

public:
	Network(
		size_t comp_nbr,
		size_t switch_nbr,
		size_t serv_nbr,
		size_t comp_max_conn,
		size_t swtch_max_conn,
		size_t serv_max_conn
	) : Device(address_) {
		address_ = 0;
		comp_nbr_ = comp_nbr;
		switch_nbr_ = switch_nbr;
		serv_nbr_ = serv_nbr;
		comp_max_conn_ = comp_max_conn;
		swtch_max_conn_ = swtch_max_conn;
		serv_max_conn_ = serv_max_conn;

		call_ = new Call();
		answer_ = new Answer();

		init_devices();
		random_connect();
//		find_servers();
	}

	~Network() {
		for (size_t i = 0; i < comp_nbr_; i++) {
			delete computers_[i];
		}
		for (size_t i = 0; i < switch_nbr_; i++) {
			delete switches_[i];
		}
		for (size_t i = 0; i < serv_nbr_; i++) {
			delete servers_[i];
		}

		delete call_;
		delete answer_;
	}

	void init_devices() {
		size_t i = 0;
		vector<string> names = {"tiktok", "faceapp", "snapchat"};

		while (computers_.size() < comp_nbr_) {
			Computer *comp = new Computer(address_++);
			computers_.push_back(comp);
		}
		while (switches_.size() < switch_nbr_) {
			Switch *swtch = new Switch(address_++);
			switches_.push_back(swtch);
		}
		while (servers_.size() < serv_nbr_) {
			string name;

			if (i < 3) {
				servers_.push_back(new Server(names[i], address_++));
			} else {
				cout << "Enter server name: ";
				cin >> name;
				servers_.push_back(new Server(name, address_++));
			}
			i++;
		}
		cout << endl;
	}

	size_t comp_nbr() {
		return comp_nbr_;
	}

	size_t switch_nbr() {
		return switch_nbr_;
	}

	size_t serv_nbr() {
		return serv_nbr_;
	}

	vector<Computer*> computers() {
		return computers_;
	}

	vector<Switch*> switches() {
		return switches_;
	}

	vector<Server*> servers() {
		return servers_;
	}

	Call *call() {
		return call_;
	}

	Answer *answer() {
		return answer_;
	}

	void connect(Device *devc1, Device *devc2) {
		devc1->connect(devc2);
		devc2->connect(devc1);
	}

	void random_computer_connect() {
		cout << "Computers: ";
		size_t i = 0;

		for (auto comp : computers_) {
			cout << ".";
			if (comp->conn_nbr() >= comp_max_conn_) {
				continue;
			}
			i = rand() % switch_nbr_;
			while (switches_[i]->conn_nbr() >= swtch_max_conn_ - 1) {
				i = rand() % switch_nbr_;
			}
			connect(comp, switches_[i]);
		}
		cout << " connected" << endl;
	}

	void random_switch_connect() {
		cout << "Switches ";
		size_t j = 0;

		for (size_t i = 0; i < switch_nbr_; i++) {
			cout << ".";
			if (switches_[i]->conn_nbr() >= swtch_max_conn_) {
				continue;
			}
			j = rand() % switch_nbr_;
			while (i == j || switches_[i]->connected(switches_[j])
			|| switches_[j]->conn_nbr() >= swtch_max_conn_) {
				j = rand() % switch_nbr_;
			}
			connect(switches_[i], switches_[j]);
		}
		cout << " connected" << endl;
	}

	void random_server_connect() {
		cout << "Servers ";
		size_t i = 0;

		for (auto serv : servers_) {
			cout << ".";
			if (serv->conn_nbr() >= serv_max_conn_) {
				continue;
			}
			while (serv->conn_nbr() < serv_max_conn_) {
				i = rand() % switch_nbr_;
				while (serv->connected(switches_[i])
				|| switches_[i]->conn_nbr() >= 1) {
					i = rand() % switch_nbr_;
				}
				connect(serv, switches_[i]);
			}
		}
		cout << " connected" << endl;
	}

	void random_connect() {
		cout << "Connecting" << endl;
		random_server_connect();
		random_computer_connect();
		random_switch_connect();
		cout << endl;
	}
};

#endif
