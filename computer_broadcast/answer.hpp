#ifndef ANSWER_HH
#define ANSWER_HH

#include "head.hh"

class Answer : public Call {
private:
	set<string>	servers_;	// available servers

public:
	Answer() : Call() {}

	~Answer() {
		servers_.clear();
	}

	bool have(string serv) {
		if (servers_.count(serv)) {	
			return true;
		} else {
			return false;
		}
	}

	void insert(string serv) {
		servers_.insert(serv);
	}

	void clear() {
		servers_.clear();
	}

	set<string> servers() {
		return servers_;
	}
};

#endif