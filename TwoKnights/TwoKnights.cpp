#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;

    for (long long k = 1; k <= n; k++) {
        long long totalWays = ((k * k) * (k * k - 1)) / 2;
        long long attackingPairs = 4 * (k - 1) * (k - 2);
        cout << totalWays - attackingPairs << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}