#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <climits>

using namespace std;

long long appleDivision(vector<long>& weights);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<long> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << appleDivision(weights) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

long long appleDivision(vector<long>& weights) {
    long long totalSum = 0;
    for (long w : weights)
        totalSum += w;

    set<long long> possibleSums = {0};

    for (long weight : weights) {
        set<long long> newSums;
        for (long long sum : possibleSums) {
            newSums.insert(sum + weight);
        }
        for (long long sum : newSums) {
            possibleSums.insert(sum);
        }
    }

    long long minDifference = LLONG_MAX;
    for (long long sum : possibleSums) {
        long long group2Sum = totalSum - sum;
        minDifference = min(minDifference, abs(group2Sum - sum));
    }

    return minDifference;
}
