#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int row, int col,
         int index) {
  if (index == word.length())
    return true;

  if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
      board[row][col] != word[index]) {
    return false;
  }

  char temp = board[row][col];
  board[row][col] = '#';

  bool found = dfs(board, word, row + 1, col, index + 1) || // Down
               dfs(board, word, row - 1, col, index + 1) || // Up
               dfs(board, word, row, col + 1, index + 1) || // Right
               dfs(board, word, row, col - 1, index + 1);   // Left

  board[row][col] = temp;

  return found;
}

bool exist(vector<vector<char>> &board, string word) {
  int m = board.size(), n = board[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  string word = "SEE";
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  cout << exist(board, word);

  return 0;
}
