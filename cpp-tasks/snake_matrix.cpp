/*
 * Условие:
 *    По данным числам n и m заполните двумерный массив
 *    размером n×m числами от 1 до n×m “змейкой”.
 * Формат входных данных:
 *    Вводятся два числа n и m,
 *    каждое из которых не превышает 30.
 * Формат выходных данных:
 *    Выведите полученный массив,
 *    отводя на вывод каждого элемента ровно 4 символа.
 */

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c++;
            a[i][j] = c;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i % 2)
            {
                if (a[i][m - 1 - j] < 10)
                    cout << "  ";
                else if (a[i][m - 1 - j] < 100)
                    cout << " ";
                cout << " " << a[i][m - 1 - j];
            }
            else
            {
                if (a[i][j] < 10)
                    cout << "  ";
                else if (a[i][j] < 100)
                    cout << " ";
                cout << " " << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
