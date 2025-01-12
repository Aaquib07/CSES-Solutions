#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

vector<string> generateGrayCode(int& n);

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector<string> result = generateGrayCode(n);
    for (string code : result)
        cout << code << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

vector<string> generateGrayCode(int& n) {
    vector<string> result;

    for (int i = 0; i < (1 << n); i++) {
        int value = i ^ (i >> 1);
        bitset<32> grayCode(value);
        string code = grayCode.to_string();
        result.push_back(code.substr(32 - n));
    }
    return result;
}