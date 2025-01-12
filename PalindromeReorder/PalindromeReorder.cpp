#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

string palindromeReorder(const string& s);

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;

    cout << palindromeReorder(s) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

string palindromeReorder(const string& s) {
    unordered_map<char, long> hashmap;

    for (char ch : s)
        hashmap[ch]++;
    
    int oddCount = 0;
    char oddChar = '\0';

    for (const auto& entry : hashmap) {
        if (entry.second % 2 == 1) {
            oddCount++;
            oddChar = entry.first;
        }
        if (oddCount > 1)
            return "NO SOLUTION";
    }

    string half = "";
    string middle = "";

    if (oddCount == 1)
        middle = string(hashmap[oddChar], oddChar);
    
    for (const auto& entry : hashmap) {
        if (entry.first != oddChar)
            half += string(entry.second / 2, entry.first);
    }

    string palindrome = half + middle;
    reverse(half.begin(), half.end());
    palindrome += half;

    return palindrome;
}