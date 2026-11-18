#include <iostream>
#include <string>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long maxReps = 0;
    long long currentReps = 1;
    string sequence;
    cin >> sequence;

    char lastChar = sequence[0];
    
    for (long long i = 1; i < sequence.size(); i++) {
        if (sequence[i] == lastChar)
            currentReps++;
        else {
            maxReps = max(maxReps, currentReps);
            currentReps = 1;
            lastChar = sequence[i];
        }
    }
    maxReps = max(maxReps, currentReps);
    cout << maxReps;
    return 0;
}