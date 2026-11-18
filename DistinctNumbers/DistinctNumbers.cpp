#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distinctNumbers(vector<long>& arr) {
    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1])
            count++;
    }
    return count;
}


int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    vector<long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = distinctNumbers(arr);
    cout << result << endl;
    return 0;
}
