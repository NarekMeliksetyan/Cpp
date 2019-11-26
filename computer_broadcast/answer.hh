#ifndef ANSWER_HH
#define ANSWER_HH

#include "head.hh"

class Answer : public Call {
private:
	set<string>	servers;	// available servers

public:
	Answer() : Call() {}

	~Answer() {
		servers.clear();
	}

	bool have(string serv) {
		if (servers.count(serv)) {	
			return true;
		} else {
			return false;
		}
	}

	void insert(string serv) {
		servers.insert(serv);
	}

	void clear() {
		servers.clear();
	}

	set<string> get_servers() {
		return servers;
	}
};

#endif