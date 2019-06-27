#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct man {
    string a;
    float b;
};

bool cmp(man a, man b) {
    return a.b > b.b;
}

int main() {
    int n;
    cin >> n;
    
    vector <man> a(n);
    string s, s1;
    float b, c;
    
    for (int i = 0; i < n; i++) {
        cin >> s >> s1 >> b >> c;
        b += c;
        cin >> c;
        b = (b + c) / 3;
        a[i].a = s + " " + s1;
        a[i].b = b;
    }
    
    stable_sort(a.begin(), a.end(), cmp);
    
    for (int i = 0; i < n; i++)
        cout << a[i].a << endl;
    
    return 0;
}
