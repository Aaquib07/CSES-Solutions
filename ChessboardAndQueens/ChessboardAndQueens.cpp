#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int row, int col, vector<bool>& columns, vector<bool>& mainDiagonals, vector<bool>& antiDiagonals);
int placeQueens(int row, vector<string>& board, vector<bool>& columns, vector<bool>& mainDiagonals, vector<bool>& antiDiagonals);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> board(8);

    for (int i = 0; i < 8; i++)
        cin >> board[i];
    
    vector<bool> columns(8, false);
    vector<bool> mainDiagonals(15, false);
    vector<bool> antiDiagonals(15, false);

    cout << placeQueens(0, board, columns, mainDiagonals, antiDiagonals) << endl;

    fclose(stdin);
    fclose(stdout);
}

bool isSafe(int row, int col, vector<bool>& columns, vector<bool>& mainDiagonals, vector<bool>& antiDiagonals) {
    return !columns[col] && !mainDiagonals[row - col + 7] && !antiDiagonals[row + col];
}

int placeQueens(int row, vector<string>& board, vector<bool>& columns, vector<bool>& mainDiagonals, vector<bool>& antiDiagonals) {
    // All queens placed successfully
    if (row == 8)
        return 1;
    
    int count = 0;
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '.' && isSafe(row, col, columns, mainDiagonals, antiDiagonals)) {
            // Place queen
            columns[col] = mainDiagonals[row - col + 7] = antiDiagonals[row + col] = true;
            count += placeQueens(row + 1, board, columns, mainDiagonals, antiDiagonals);
            // Remove queen
            columns[col] = mainDiagonals[row - col + 7] = antiDiagonals[row + col] = false;
        }
    }
    return count;
}