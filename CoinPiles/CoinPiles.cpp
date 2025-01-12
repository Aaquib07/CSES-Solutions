#include <iostream>

using namespace std;

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int a, b;
        cin >> a >> b;
        
        if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}