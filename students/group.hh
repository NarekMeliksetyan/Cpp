#ifndef GROUP_HH
#define GROUP_HH

#include "head.hh"

class Group : public Student {
private:
	size_t	stud_nbr_;		// number of students

	vector<Student*>	students_;		// students in the group

public:
	Group(size_t stud_nbr) : Student(id_) {
		id_ = 0;
		stud_nbr_ = stud_nbr;
		init_students();
	}

	~Group() {
		for (int i = 0; i < stud_nbr_; i++) {
			delete students_[i];
		}
	}

	size_t stud_nbr() {
		return stud_nbr_;
	}

	vector<Student*> students() {
		return students_;
	}

	void init_students() {
		while (students_.size() < stud_nbr_) {
			Student *stud = new Student(id_++);
			students_.push_back(stud);
		}
	}
};

#endif