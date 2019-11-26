#ifndef CALL_HH
#define CALL_HH

#include "head.hh"

class Call {
private:
	set<int>	checked;	// checked devices

public:
	Call() {}

	virtual ~Call() {
		checked.clear();
	}

	virtual bool have(size_t connection) {
		if (checked.count(connection)) {
			return true;
		} else {
			return false;
		}
	}

	virtual void insert(size_t connection) {
		checked.insert(connection);
	}

	virtual void clear() {
		checked.clear();
	}
};

#endif