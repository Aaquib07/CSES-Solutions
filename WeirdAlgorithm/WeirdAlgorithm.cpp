#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;

    cout << n << " ";
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
            cout << n << " ";
        }
        else {
            n = 3 * n + 1;
            cout << n << " ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}