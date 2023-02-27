/*
 * Условие:
 *    Первая строка содержит количество предметов 1≤𝑛≤103 и вместимость рюкзака
 *    0≤W≤2*10^6. Каждая из следующих 𝑛 строк задаёт стоимость 0≤𝑐𝑖≤2*10^6
 *    и объём 0<𝑤𝑖≤2*10^6 предмета (𝑛, 𝑊, 𝑐𝑖, 𝑤𝑖 — целые числа).
 *
 *    Выведите максимальную стоимость частей предметов (от каждого предмета
 *    можно отделить любую часть, стоимость и объём при этом
 *    пропорционально уменьшатся), помещающихся в данный рюкзак,
 *    с точностью не менее трёх знаков после запятой.
 */

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int items_count, bag_volume;
    cin >> items_count >> bag_volume;
    list<pair<int, int>> items;
    for (size_t i = 0; i < items_count; i++)
    {
        int cost = 0, volume = 0;
        cin >> cost >> volume;
        items.push_back(make_pair(cost, volume));
    }
    items.sort([](const pair<int, int> &a, const pair<int, int> &b)
               { return (((double)a.first) / ((double)a.second)) > (((double)b.first) / ((double)b.second)); });
    double bag_cost = 0.0;
    while (bag_volume > 0)
    {
        if (items.empty())
            break;
        unsigned int item_cost = (*items.begin()).first;
        unsigned int item_volume = (*items.begin()).second;
        if (bag_volume < item_volume)
        {
            bag_cost += ((double)bag_volume) * ((double)item_cost) / ((double)item_volume);
            bag_volume = 0;
        }
        else
        {
            bag_cost += (double)item_cost;
            bag_volume -= item_volume;
            items.pop_front();
        }
    }
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);
    cout << bag_cost << endl;
    return 0;
}
