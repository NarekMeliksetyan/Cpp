#include <iostream>

using namespace std;

int sum(int);
int min(int);

int main() {
	int n;
	cout << "Enter the hight of the building: ";
	cin >> n;
	cout << "The aswer is " << min(n) << endl;
	return 0;
}

/* Нахождение суммы чисел от 1 до n
 * с использованием рекурсии
 */
int sum(int n) {
	if (n == 0)
		return 0;
	return n + sum(n - 1);
}

/* Нахождение минимального количества попыток,
 * путём решения следующего неравенства:
 * n*(n-1)*(n-2) ... 1 >= 100
 */
int min(int n) {
	int i = 1;
	while (sum(i) < n) 
		i++;
	return i;
}
