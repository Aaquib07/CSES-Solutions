#include <bits/stdc++.h>

using namespace std;

int countPartitions(long long sum, vector<int>& arr) {
    int partitions = 1;
    long long currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (currentSum + arr[i] > sum) {
            partitions++;
            currentSum = 0;
        }
        currentSum += arr[i];
    }
    return partitions;
}

long long arrayDivision(int n, int k, vector<int>& arr) {
    long long left = *max_element(arr.begin(), arr.end());
    long long right = accumulate(arr.begin(), arr.end(), 0LL);

    while (left <= right) {
        long long mid = (left + right) >> 1;
        if (countPartitions(mid, arr) <= k)
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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long result = arrayDivision(n, k, arr);
    cout << result << endl;
    
    return 0;
}



