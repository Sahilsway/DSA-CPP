#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char dig) {

  // Horizontal
  for (int j = 0; j < 9; j++) {
    if (board[row][j] == dig) {
      return false;
    }
  }

  // Vertical
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == dig) {
      return false;
    }
  }

  int sr = (row / 3) * 3;
  int sc = (col / 3) * 3;

  for (int i = sr; i < sr + 3; i++) {
    for (int j = sc; j < sc + 3; j++) {
      if (board[i][j] == dig) {
        return false;
      }
    }
  }

  return true;
}

bool helper(vector<vector<char>> &board, int row, int col) {
  // Base case
  if (row == 9) {
    return true;
  }

  int nextRow = row, nextCol = col + 1;
  if (nextCol == 9) {
    nextRow = row + 1;
    nextCol = 0;
  }

  if (board[row][col] != '.') {
    return helper(board, nextRow, nextCol);
  }

  for (char dig = '1'; dig <= '9'; dig++) {
    if (isSafe(board, row, col, dig)) {
      board[row][col] = dig;

      if (helper(board, nextRow, nextCol)) {
        return true;
      }

      board[row][col] = '.';
    }
  }

  return false;
}

void solveSudoku(vector<vector<char>> &board) {
  bool validSudoku = helper(board, 0, 0);
  cout << validSudoku << endl;
  if (validSudoku) {
    // Print sudoku
    for (const auto &rows : board) {
      for (char val : rows) {
        cout << val << " ";
      }
      cout << endl;
    }
  } else {
    cout << "Solution not available" << endl;
  }
}

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  solveSudoku(board);

  return 0;
}
