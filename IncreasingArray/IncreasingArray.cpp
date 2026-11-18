#include <iostream>
#include <vector>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    
    long long minMoves = 0;

    if (n == 1)
        cout << minMoves;
    else {
        for (long long i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                minMoves += arr[i - 1] - arr[i];
                arr[i] = arr[i - 1];
            }
        }
        cout << minMoves;
    }
    return 0;
}