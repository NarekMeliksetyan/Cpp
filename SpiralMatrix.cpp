#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int s = 1;
    
    if (m < 2) {
        for (int i = 1; i <= n; i++) {
            cout.width(4);
            cout << i;
        }
        return 0;
    }

    if (n < 2) {
        for (int i = 1; i <= m; i++) {
            cout << " ";
            cout.width(4);
            cout << i << endl;
        }
        return 0;
    }
 
    int a[100][100];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
 
    // Заполняем периметр массива по часовой стрелке.
    for (int y = 0; y < n; y++) {
        a[0][y] = s;
            s++;
    }
    for (int x = 1; x < m; x++) {
        a[x][n - 1] = s;
        s++;
    }
    for (int y = n - 2; y >= 0; y--) {
        a[m - 1][y] = s;
        s++;
    }
    for (int x = m - 2; x > 0; x--) {
        a[x][0] = s;
        s++;
    }
 
    /* Периметр заполнен. Продолжаем заполнять массив и задаём
     * координаты ячейки, которую необходимо заполнить следующей.
     */
    int c = 1;
    int d = 1;
 
    while (s < m * n) {
        // Вправо
        while (a[c][d + 1] == 0) {
            a[c][d] = s;
            s++;
            d++;
        }
        // Вниз
        while (a[c + 1][d] == 0) {
            a[c][d] = s;
            s++;
            c++;
        }
        // Влево
        while (a[c][d - 1] == 0) {
            a[c][d] = s;
            s++;
            d--;
        }
 
        // Вверх
        while (a[c - 1][d] == 0) {
            a[c][d] = s;
            s++;
            c--;
        }
    }
 
    /* При данном решении в центре всегда остаётся незаполненная ячейка.
     * Убираем её при помощи следующего цикла.
     */
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
                a[i][j] = s;
    
    cout << " ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout.width(4);
            cout << a[i][j];
        } cout << endl;
    } 
    
   return 0;
}
