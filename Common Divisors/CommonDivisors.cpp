#include <bits/stdc++.h>

using namespace std;

long long commonDivisors(long long n, vector<long long>& arr) {
    const long long MAX = 1e6 + 1;
    vector<long long> freq(MAX, 0);

    for (long long x : arr)
        freq[x]++;
    
    for (long long d = MAX - 1; d > 0; d--) {
        long long count = 0LL;

        for (long long m = d; m < MAX; m += d) {
            count += freq[m];
            if (count >= 2)
                return d;
        }
    }
    return 1;
}

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n;
    cin >> n;

    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    
    long long result = commonDivisors(n, arr);
    cout << result << endl;
    
    return 0;
}


