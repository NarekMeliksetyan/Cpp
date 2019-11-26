#include "head.hh"

int main()
{
	unique_ptr<Network> net(new Network(20, 10, 3, 1 , 4, 2));

	cout << "Computers:" << endl;
	for (auto comp : net->get_computers()) {
		cout << comp->get_address();
		comp->find_servers(net->get_call(), net->get_answer());
		cout << endl;
		net->get_call()->clear();
		net->get_answer()->clear();
	}
	cout << endl;

	cout << "Switches:" << endl;
	for (auto swtch : net->get_switches()) {
		cout << swtch->get_address() << ":";
		for (auto conn : swtch->get_connections()) {
			cout << " " << conn->get_address();
		}
		cout << " - " << swtch->get_calls() << " call";
		if (swtch->get_calls() > 1) {
			cout << "s";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Servers:" << endl;
	for (auto serv : net->get_servers()) {
		cout << serv->get_name() << ":";
		for (auto conn : serv->get_connections()) {
			cout << " " << conn->get_address();
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
