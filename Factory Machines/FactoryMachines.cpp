#include <bits/stdc++.h>

using namespace std;

bool isPossible(long long time, vector<long long>& arr, long long t) {
    long long count = 0;
    for (int x: arr) {
        count += time / x;
        if (count >= t)
            return true;
    }
    return false;
}

long long factoryMachines(long long n, long long t, vector<long long>& arr) {
    long long left = 1;
    long long right = 1e18;

    while (left <= right) {
        long long mid = (left + right) >> 1;
        if (isPossible(mid, arr, t))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, t;
    cin >> n >> t;

    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    
    long long result = factoryMachines(n, t, arr);
    cout << result << endl;
    
    return 0;
}

