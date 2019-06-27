#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n+1);
    
    for (int i = 1; i <= n; i++)
        a[i] = 1;
    
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        
        for (int j = l; j <= r; j++)
            a[j] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        if (a[i])
            cout << "I";
        else
            cout << ".";
    }

    return 0;
}
