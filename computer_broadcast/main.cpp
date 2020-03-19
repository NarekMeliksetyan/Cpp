#include "head.hh"

int main()
{
	auto call = make_shared<Call>();
	auto answer = make_shared<Answer>();
	shared_ptr<Network> net(new Network(20, 10, 3, 1 , 4, 2));

	cout << "Computers:" << endl;
	for (auto comp : net->computers()) {
		cout << comp->address();
		comp->find_servers(call.get(), answer.get());
		cout << endl;
		call->clear();
		answer->clear();
	}
	cout << endl;

	cout << "Switches:" << endl;
	for (auto swtch : net->switches()) {
		cout << swtch->address() << ":";
		for (auto conn : swtch->connections()) {
			cout << " " << conn->address();
		}
		cout << " - " << swtch->calls() << " call";
		if (swtch->calls() > 1) {
			cout << "s";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Servers:" << endl;
	for (auto serv : net->servers()) {
		cout << serv->name() << ":";
		for (auto conn : serv->connections()) {
			cout << " " << conn->address();
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
