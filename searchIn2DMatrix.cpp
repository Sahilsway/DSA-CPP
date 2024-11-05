#include <iostream>
#include <vector>

using namespace std;

bool searchInRow(vector<vector<int>> &mat, int target, int row) {
  int n = mat[row].size();
  int str = 0, end = n - 1;

  while (str <= end) {
    int mid = str + (end - str) / 2;
    if (target == mat[row][mid]) {
      return true;
    } else if (target < mat[row][mid]) {
      end = mid - 1;
    } else {
      str = mid + 1;
    }
  }
  return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target) {
  int m = mat.size(), n = mat[0].size();

  int strRow = 0, endRow = m - 1;

  while (strRow <= endRow) {
    int midRow = strRow + (endRow - strRow) / 2;

    if (target >= mat[midRow][0] && target <= mat[midRow][n - 1]) {
      return searchInRow(mat, target, midRow);
    } else if (target > mat[midRow][n - 1]) {
      strRow = midRow + 1;
    } else {
      endRow = midRow - 1;
    }
  }
  return false;
}

int main() {
  int target = 34;
  vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  cout << searchMatrix(mat, target);

  return 0;
}
