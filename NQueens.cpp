#include<iostream>

using namespace std;
 
bool IsSafePos(int*, int, int, int);
void backtracking(int, int&, int, int*);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int *board = new int[n];
    for (int i = 0; i < n; i++)
        board[i] = 0;

    // Вызов рекурсивной фугкции обхода доски
    int count = 0;
    backtracking(0, count, n, board);

    // Вывод результата в зависимотри от количества решений
    if (count == 0)
	    cout << "There is no solution.";
    else if (count == 1)
	    cout << "There is 1 solution.";
    else
	    cout << "There are " << count << " solutions.";
    cout << endl;

    delete []board;
    return 0;
}

/* Проверка позиции на безопасность
 */
bool IsSafePos(int *board, int k, int y, int N) {
    int i = 0;
    while (i < k && y != board[i] && abs(k - i) != abs(y - board[i]))
	    i++;
    if (i == k)
        return true;
    else
        return false;
}

/* Рекурсивная функция для обхода доски
 */
void backtracking(int k, int &count, int N, int *board) {
    int i, y;
    for (y = 0; y < N; y++) {
        if (IsSafePos(board, k, y, N)) {
            board[k] = y;
            if (k == N - 1)
                count++;

            backtracking(k + 1, count, N, board);
        }
    }
}
