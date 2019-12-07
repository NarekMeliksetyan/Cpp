#ifndef GROUP_HH
#define GROUP_HH

#include "head.hh"

class Group : public Student {
private:
	size_t	stud_nbr_;		// number of students

	vector<Student*>	students_;

public:
	Group(string name) {
		name_ = name;
	}

	size_t stud_nbr() {
		return stud_nbr_;
	}

	vector<Student*> students() {
		return students_;
	}
};

#endif