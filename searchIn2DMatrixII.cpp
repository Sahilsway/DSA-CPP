#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target) {
  int m = mat.size(), n = mat[0].size();
  int row = 0, col = n - 1;

  while (col >= 0 && row < m) {
    if (target == mat[row][col]) {
      return true;
    } else if (target > mat[row][col]) {
      row++;
    } else {
      col--;
    }
  }

  return false;
}

int main() {
  int target = 22;
  vector<vector<int>> mat = {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  cout << searchMatrix(mat, target);

  return 0;
}
