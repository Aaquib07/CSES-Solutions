#include <bits/stdc++.h>

using namespace std;

int minimizingCoins(int n, int x, vector<int>& coins);
int recursion(int target, vector<int>& coins, vector<int>& memo);

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    int result = minimizingCoins(n, x, coins);
    cout << (result == INT_MAX - 1 ? -1 : result) << endl;
    
    return 0;
}

int minimizingCoins(int n, int x, vector<int>& coins) {
    vector<int> memo(x + 1, -1);
    return recursion(x, coins, memo);
}

int recursion(int target, vector<int>& coins, vector<int>& memo) {
    if (target < 0)
        return INT_MAX - 1;
    
    if (target == 0)
        return 0;
    
    if (memo[target] != -1)
        return memo[target];
    
    int minCoins = INT_MAX - 1;
    for (int i = 0; i < coins.size(); i++)
        minCoins = min(minCoins, 1 + recursion(target - coins[i], coins, memo));

    memo[target] = minCoins;
    return memo[target];
}