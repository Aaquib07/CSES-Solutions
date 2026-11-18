#include <iostream>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n;
    cin >> n;

    if (n == 1)
        cout << 1;
    else if (n == 2 || n == 3)
        cout << "NO SOLUTION";
    else {
        for (long long i = 2; i <= n; i += 2)
            cout << i << " ";

        for (long long i = 1; i <= n; i += 2)
            cout << i << " ";
    }
    return 0;
}