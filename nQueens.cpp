#include <iostream>
#include <vector>

using namespace std;

// TC : O(n)
bool isSafe(vector<string> &board, int n, int row, int col) {

  // Check col
  for (int i = 0; i < n; i++) {
    if (board[i][col] == 'Q') {
      return false;
    }
  }

  // Check row
  for (int j = 0; j < n; j++) {
    if (board[row][j] == 'Q') {
      return false;
    }
  }

  // Check left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  // Check right diagonal
  for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
    if (board[i][j] == 'Q') {
      return false;
    }
  }

  return true;
}

// TC : O(n!)
void nQueens(vector<string> &board, int n, int row,
             vector<vector<string>> &res) {
  if (row == n) {
    res.push_back(board);
    return;
  }

  for (int j = 0; j < n; j++) {
    if (isSafe(board, n, row, j)) {
      board[row][j] = 'Q';
      nQueens(board, n, row + 1, res);
      board[row][j] = '.';
    }
  }
}

// TC : O(1)
vector<vector<string>> solveNQueens(int n) {
  vector<string> board(n, string(n, '.'));
  vector<vector<string>> res;

  nQueens(board, n, 0, res);

  return res;
}

// TOTAL TC : O(n + n! + 1) => O(n!)
int main() {
  int n = 4;
  vector<vector<string>> res = solveNQueens(n);

  for (const auto &poss : res) {
    for (string row : poss) {
      cout << row << endl;
    }
    cout << endl;
  }

  return 0;
}
