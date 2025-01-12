#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void createStrings(string s);

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;

    createStrings(s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

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