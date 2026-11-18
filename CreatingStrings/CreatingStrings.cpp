#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void createStrings(string s) {
    set<string> result;
    sort(s.begin(), s.end());

    do {
        result.insert(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << result.size() << endl;
    for (const string& perm : result)
        cout << perm << endl;
}

int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;

    createStrings(s);
    return 0;
}