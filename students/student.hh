#ifndef STUDENT_HH
#define STUDENT_HH

#include "head.hh"

class Student {
protected:
	int			av_;		// average mark
	size_t		id_;		// student's id
	string		name_;		// student's name
	vector<int>	marks_;		// stident's marks

public:
	Student(size_t id) {
		av_ = 0;
		id_ = id;
		init_student();
	}

	size_t id() {
		return id_;
	}

	string name() {
		return name_;
	}

	void init_student() {
		cout << "Student's name:" << endl;
		cin >> name_;
		add_marks();
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

	void add_mark(int mark) {
		if (mark >= 2 && mark <= 5) {
			marks_.push_back(mark);
		} else {
			cout << "Invalid mark" << endl;
		}
	}

	void add_marks() {
		int mark = 0;

		cout << "Enter marks or enter 0 to stop:" << endl;
		cin >> mark;

		while (mark) {
			add_mark(mark);
			cin >> mark;
		}
	}
};

#endif
