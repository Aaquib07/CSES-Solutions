#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> arr(n - 1, 0);
    for (long long i = 0; i < n - 1; i++)
        cin >> arr[i];
    
    long long xor1 = 0;
    long long xor2 = 0;

    for (long long i = 0; i < n + 1; i++)
        xor1 ^= i;
    
    for (long long num : arr)
        xor2 ^= num;
    
    long long result = xor1 ^ xor2;
    cout << result;
    fclose(stdin);
    fclose(stdout);
    return 0;
}