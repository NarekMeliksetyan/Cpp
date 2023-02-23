#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned char a = 255;
    unsigned char b = 255;

    for (int i = 0; i < 10; i++)
    {
        std::bitset<8> x(a);
        cout << (int)a << '\t' << x << endl;
        a = a >> 1;

        std::bitset<8> y(b);
        b = b << 1;
        cout << (int)b << '\t' << y << endl
             << endl;
    }
}