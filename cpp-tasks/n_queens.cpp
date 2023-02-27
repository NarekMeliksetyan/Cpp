/*
 * Условие:
 *    Дано число N. Определите, сколькими способами можно расставить
 *    на доске N×N N ферзей, не бьющих друг друга.
 * Формат входных данных:
 *    Задано единственное число N. (N ≤ 10)
 * Формат выходных данных
 *    Выведите ответ на задачу.
 * Подсказка:
 *    Напишите рекурсивную функцию, которая пытается поставить ферзя в
 *    очередной столбец. Если на эту клетку ставить ферзя нельзя
 *    (он бьет предыдущих), то такой вариант даже не стоит рассматривать.
 *    Успешно поставив ферзя в последний столбец, увеличивайте счетчик.
 */

#include <iostream>

using namespace std;

bool IsSafePos(int *, int, int, int);
void backtracking(int, int &, int, int *);

int main()
{
    int n, count = 0;
    cout << "Enter n: ";
    cin >> n;

    int *board = new int[n];
    for (int i = 0; i < n; i++)
        board[i] = 0;

    backtracking(0, count, n, board);

    if (count == 0)
        cout << "There is no solution.";
    else if (count == 1)
        cout << "There is 1 solution.";
    else
        cout << "There are " << count << " solutions.";
    cout << endl;

    delete[] board;
    return 0;
}

bool IsSafePos(int *board, int k, int y, int N)
{
    int i = 0;
    while (i < k && y != board[i] && abs(k - i) != abs(y - board[i]))
        i++;
    if (i == k)
        return true;
    else
        return false;
}

void backtracking(int k, int &count, int N, int *board)
{
    int i, y;
    for (y = 0; y < N; y++)
    {
        if (IsSafePos(board, k, y, N))
        {
            board[k] = y;
            if (k == N - 1)
                count++;
            backtracking(k + 1, count, N, board);
        }
    }
}
