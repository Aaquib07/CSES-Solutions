#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distinctNumbers(vector<long>& arr);

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = distinctNumbers(arr);
    cout << result << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

int distinctNumbers(vector<long>& arr) {
    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1])
            count++;
    }
    return count;
}