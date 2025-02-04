#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long coinCombinations(long long n, long long x, vector<long long>& c);
long long recursion(long long index, long long target, vector<long long>& c, vector<vector<long long>>& memo);

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, x;
    cin >> n >> x;
    vector<long long> c(n);
    for (long long i = 0; i < n; i++)
        cin >> c[i];
    cout << coinCombinations(n, x, c) << endl;
    return 0;
}

long long coinCombinations(long long n, long long x, vector<long long>& c) {
    vector<vector<long long>> memo(n, vector<long long>(x + 1, -1));
    return recursion(n - 1, x, c, memo);
}

long long recursion(long long index, long long target, vector<long long>& c, vector<vector<long long>>& memo) {
    if (index == 0)
        return (target % c[index] == 0);

    if (memo[index][target] != -1)
        return memo[index][target];

    long long notTake = recursion(index - 1, target, c, memo);
    long long take = 0;
    if (c[index] <= target)
        take += recursion(index, target - c[index], c, memo);
    memo[index][target] = (take + notTake) % MOD;
    return memo[index][target];
}