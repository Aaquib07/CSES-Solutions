#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    int result = 0;
    
    while (n > 0) {
        n /= 5;
        result += n;
    }
    cout << result;
    fclose(stdin);
    fclose(stdout);
    return 0;
}