#include <iostream>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    int result = 0;
    
    while (n > 0) {
        n /= 5;
        result += n;
    }
    cout << result;

    return 0;
}