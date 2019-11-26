#ifndef NETW0RK_HH
#define NETW0RK_HH

#include "head.hh"

class Network : public Device {
private:
	size_t		comp_nbr;			// number of computers
	size_t		switch_nbr;			// number of switches
	size_t		serv_nbr;			// number of srvers
	size_t		comp_max_conn;		// max number of computer connections
	size_t		swtch_max_conn;		// max number of switch connections
	size_t		serv_max_conn;		// max number of server connections

	Call		*call;				// call to server
	Answer		*answer;			// answer to call

	set<int>			checked;		// checked addresses during connection checking
	vector<Computer*>	computers;		// computers in the network
	vector<Switch*>		switches;		// swtiches in the network
	vector<Server*>		servers;		// servers in the network

public:
	Network(
		size_t comp_nbr,
		size_t switch_nbr,
		size_t serv_nbr,
		size_t comp_max_conn,
		size_t swtch_max_conn,
		size_t serv_max_conn
	) : Device(address) {
		this->address = 0;
		this->comp_nbr = comp_nbr;
		this->switch_nbr = switch_nbr;
		this->serv_nbr = serv_nbr;
		this->comp_max_conn = comp_max_conn;
		this->swtch_max_conn = swtch_max_conn;
		this->serv_max_conn = serv_max_conn;

		this->call = new Call();
		this->answer = new Answer();

		init_devices();
		random_connect();
//		find_servers();
	}

	~Network() {
		for (size_t i = 0; i < comp_nbr; i++) {
			delete computers[i];
		}
		for (size_t i = 0; i < switch_nbr; i++) {
			delete switches[i];
		}
		for (size_t i = 0; i < serv_nbr; i++) {
			delete servers[i];
		}

		delete call;
		delete answer;
	}

	void init_devices() {
		size_t i = 0;
		vector<string> names = {"tiktok", "faceapp", "snapchat"};

		while (computers.size() < comp_nbr) {
			Computer *comp = new Computer(address++);
			computers.push_back(comp);
		}
		while (switches.size() < switch_nbr) {
			Switch *swtch = new Switch(address++);
			switches.push_back(swtch);
		}
		while (servers.size() < serv_nbr) {
			string name;

			if (i < 3) {
				servers.push_back(new Server(names[i], address++));
			} else {
				cout << "Enter server name: ";
				cin >> name;
				servers.push_back(new Server(name, address++));
			}
			i++;
		}
		cout << endl;
	}

	size_t get_comp_nbr() {
		return comp_nbr;
	}

	size_t get_switch_nbr() {
		return switch_nbr;
	}

	size_t get_serv_nbr() {
		return serv_nbr;
	}

	vector<Computer*> get_computers() {
		return computers;
	}

	vector<Switch*> get_switches() {
		return switches;
	}

	vector<Server*> get_servers() {
		return servers;
	}

	Call *get_call() {
		return call;
	}

	Answer *get_answer() {
		return answer;
	}

	void connect(Device *devc1, Device *devc2) {
		devc1->connect(devc2);
		devc2->connect(devc1);
	}

	void random_computer_connect() {
		cout << "Computers: ";
		size_t i = 0;

		for (auto comp : get_computers()) {
			cout << ".";
			if (comp->get_conn_nbr() >= comp_max_conn) {
				continue;
			}
			i = rand() % switch_nbr;
			while (switches[i]->get_conn_nbr() >= swtch_max_conn - 1) {
				i = rand() % switch_nbr;
			}
			connect(comp, switches[i]);
		}
		cout << " connected" << endl;
	}

	void random_switch_connect() {
		cout << "Switches ";
		size_t j = 0;

		for (size_t i = 0; i < switch_nbr; i++) {
			cout << ".";
			if (switches[i]->get_conn_nbr() >= swtch_max_conn) {
				continue;
			}
			j = rand() % switch_nbr;
			while (i == j || switches[i]->connected(switches[j])
			|| switches[j]->get_conn_nbr() >= swtch_max_conn) {
				j = rand() % switch_nbr;
			}
			connect(switches[i], switches[j]);
		}
		cout << " connected" << endl;
	}

	void random_server_connect() {
		cout << "Servers ";
		size_t i = 0;

		for (auto serv : servers) {
			cout << ".";
			if (serv->get_conn_nbr() >= serv_max_conn) {
				continue;
			}
			while (serv->get_conn_nbr() < serv_max_conn) {
				i = rand() % switch_nbr;
				while (serv->connected(switches[i])
				|| switches[i]->get_conn_nbr() >= 1) {
					i = rand() % switch_nbr;
				}
				connect(serv, switches[i]);
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
