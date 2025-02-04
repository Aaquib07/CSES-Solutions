#include <bits/stdc++.h>

using namespace std;

long long apartments(long long n, long long m, long long k, vector<long long>& a, vector<long long>& b);

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long m, n, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> b(m);
    for (long long i = 0; i < m; i++)
        cin >> b[i];
    cout << apartments(n, m, k, a, b) << endl;
    return 0;
}

long long apartments(long long n, long long m, long long k, vector<long long>& a, vector<long long>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long i = 0;
    long long j = 0;
    long long count = 0;

    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            count++;
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    return count;
}