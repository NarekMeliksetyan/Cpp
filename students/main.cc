#include "head.hh"

int main()
{
	Group *gr = new Group(3);

	cout << "Students:" << endl;
	for (auto stud : gr->students()) {
		cout << stud->id() << ": ";
		cout  << stud->name() << endl;
		cout << "Average: " << stud->av() << endl;
	}

	return 0;
}
