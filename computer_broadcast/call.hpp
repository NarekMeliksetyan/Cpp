#ifndef CALL_HH
#define CALL_HH

#include "head.hh"

class Call {
private:
	set<int>	checked_;	// checked devices

public:
	Call() {}

	virtual ~Call() {
		checked_.clear();
	}

	virtual bool have(size_t connection) {
		if (checked_.count(connection)) {
			return true;
		} else {
			return false;
		}
	}

	virtual void insert(size_t connection) {
		checked_.insert(connection);
	}

	virtual void clear() {
		checked_.clear();
	}
};

#endif