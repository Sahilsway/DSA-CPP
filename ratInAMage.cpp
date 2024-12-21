#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>> &mat, int row, int col, string path,
            vector<string> &ans) {
  int n = mat.size();
  if (row < 0 || col < 0 || row >= n || col >= n || mat[row][col] == 0 ||
      mat[row][col] == -1) {
    return;
  }

  if (row == n - 1 && col == n - 1) {
    ans.push_back(path);
    return;
  }

  mat[row][col] = -1; // Visited

  // Down
  helper(mat, row + 1, col, path + "D", ans);

  // Up
  helper(mat, row - 1, col, path + "U", ans);

  // Right
  helper(mat, row, col + 1, path + "R", ans);

  // Left
  helper(mat, row, col - 1, path + "L", ans);

  mat[row][col] = 1; // Unvisited
}

vector<string> findPath(vector<vector<int>> &mat) {
  int n = mat.size();

  vector<string> ans;
  string path = "";

  helper(mat, 0, 0, path, ans);

  return ans;
}

bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                      vector<int> &target) {

  return 0;
}

int main() {
  vector<vector<int>> math = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  vector<string> ans = findPath(math);
  for (string path : ans) {
    cout << path << endl;
  }

  return 0;
}
