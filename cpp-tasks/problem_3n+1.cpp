/*
 * Визуализация гипотезы Коллатца (3n+1 дилеемма, сиракуузская пробле́ма)
 * Берём любое натуральное число n. Если оно чётное, то делим его на 2,
 * а если нечётное, то умножаем на 3 и прибавляем 1 (получаем 3n + 1).
 * Над полученным числом выполняем те же самые действия, и так далее.
 * Гипотеза Коллатца заключается в том,
 * что какое бы начальное число n мы ни взяли, рано или поздно мы получим единицу.
 */

#include <iostream>

using namespace std;

unsigned get_counter(unsigned n)
{
    unsigned cnt = 0;
    while (n > 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        cnt++;
    }

    return cnt;
}

int main()
{
    unsigned nrange = 0;
    cin >> nrange;

    unsigned max_n = 0, max_cnt = 0;
    for (int n = 1; n <= nrange; n++)
    {
        unsigned cnt = get_counter(n);
        if (cnt > max_cnt)
        {
            max_n = n;
            max_cnt = cnt;
        }
    }

    cout << "Max " << max_n << ": " << max_cnt << endl;

    return 0;
}