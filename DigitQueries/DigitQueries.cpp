#include <iostream>

using namespace std;

int digitQueries(long long k);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long k;
        cin >> k;

        int result = digitQueries(k);
        cout << result << endl;
    }

    fclose(stdin);
    fclose(stdout);
}

int digitQueries(long long k) {
    long long digitCount = 1;
    long long rangeStart = 1;
    long long numbersInRange = 9;

    while (k > digitCount * numbersInRange) {
        k -= digitCount * numbersInRange;
        digitCount++;
        numbersInRange *= 10;
        rangeStart *= 10;
    }

    long long numberIndex = (k - 1) / digitCount;
    long long digitIndex = (k - 1) % digitCount;
    long long number = rangeStart + numberIndex;
    long long place = digitCount - digitIndex - 1;

    while (place > 0) {
        number /= 10;
        place--;
    }

    return number % 10;
}