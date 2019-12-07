#ifndef STUDENT_HH
#define STUDENT_HH

#include "head.hh"

class Student {
protected:
	int			av_;		// average mark
	size_t		id_;		// student's id
	string		name_;		// first name
	string  	lname_;		// last name
	vector<int>	marks_;		// stident's marks

public:
	Student(size_t id, string name, string lname) {
		av_ = 0;
		id_ = id;
		name_ = name;
		lname_ = lname;
	}

	int av() {
		int sum = 0;

		if (av_) {
			return av_;
		}

		for (auto mark : marks_) {
			sum += mark;
		}

		av_ = sum / marks_.size();
		return av_;
	}

	size_t id() {
		return id_;
	}
	
	string name() {
		return name_;
	}

	string lname() {
		return lname_;
	}

	void add_mark(int mark) {
		if (mark >= 2 && mark <= 5) {
			marks_.push_back(mark);
		} else {
			cout << "Invalid mark" << endl;
		}
	}

	void add_marks(int n) {
		int mark = 0;

		for (int i = 0; i < n; i++) {
			cin >> mark;
			add_mark(mark);
		}
	}

};

#endif
