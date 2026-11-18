#include <iostream>
#include <vector>

using namespace std;

void towerOfHanoi(int n, int left, int middle, int right, vector<vector<int>>& sequence) {
    if (n == 1) {
        sequence.push_back({ left, right });
        return;
    }
    
    towerOfHanoi(n - 1, left, right, middle, sequence);
    sequence.push_back({ left, right });
    towerOfHanoi(n - 1, middle, left, right, sequence);
}


int main(void) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int left = 1;
    int middle = 2;
    int right = 3;
    vector<vector<int>> sequence;
    towerOfHanoi(n, left, middle, right, sequence);

    cout << sequence.size() << endl;
    for (vector<int> pair : sequence)
        cout << pair[0] << " " << pair[1] << endl;
   
    return 0;
}
