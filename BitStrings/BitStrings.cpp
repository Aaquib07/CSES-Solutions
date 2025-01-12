#include <iostream>

using namespace std;

long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    long long result = 1;
    long long factor = 2;
    while (n > 0) {
        if (n & 1)
            result = (result * factor) % MOD;
        
        factor = (factor * factor) % MOD;
        n >>= 1;
    }
    cout << result;
    fclose(stdin);
    fclose(stdout);
    return 0;
}