/*
 * Условие:
 *    В первой строке даны целое число 1≤𝑛≤105 и массив 𝐴[1…𝑛]
 *    из 𝑛 различных натуральных чисел, не превышающих 10^9,
 *    в порядке возрастания, во второй — целое число 1≤𝑘≤10^5
 *    и 𝑘 натуральных чисел 𝑏1,…,𝑏𝑘, не превышающих 10^9.
 *
 *    Для каждого 𝑖 от 1 до 𝑘 необходимо вывести индекс 1≤𝑗≤𝑛,
 *    для которого 𝐴[𝑗]=𝑏𝑖, или −1, если такого 𝑗 нет.
 */

#include <iostream>
#include <vector>

using namespace std;

int bin_search(int val, vector<int> &mas)
{
    int l = 0;
    int r = mas.size() - 1;

    if (val > mas.at(r))
        return -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        unsigned int elem = mas.at(m);
        if (elem == val)
            return m + 1;
        if (val > elem)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    int num_count = 0;
    cin >> num_count;
    vector<int> mas;

    while (num_count-- > 0)
    {
        int val = 0;
        cin >> val;
        mas.push_back(val);
    }
    cin >> num_count;
    vector<int> nums_to_seach;

    while (num_count-- > 0)
    {
        int val = 0;
        cin >> val;
        nums_to_seach.push_back(val);
    }
    for (auto val : nums_to_seach)
        cout << bin_search(val, mas) << " ";
    cout << endl;
    cout.flush();
    return 0;
}
