#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat) {
  int m = mat.size(), n = mat[0].size();
  int sRow = 0, eRow = m - 1, sCol = 0, eCol = n - 1;
  vector<int> result;

  while (sRow <= eRow && sCol <= eCol) {
    // Top
    for (int i = sCol; i <= eCol; i++) {
      result.push_back(mat[sRow][i]);
    }

    // Right
    for (int i = sRow + 1; i <= eRow; i++) {
      result.push_back(mat[i][eCol]);
    }

    // Bottom
    for (int i = eCol - 1; i >= sCol; i--) {
      if (sRow == eRow) {
        break;
      }
      result.push_back(mat[eRow][i]);
    }

    // Left
    for (int i = eRow - 1; i >= sRow + 1; i--) {
      if (sCol == eCol) {
        break;
      }
      result.push_back(mat[i][sCol]);
    }
    sRow++, eRow--, sCol++, eCol--;
  }

  return result;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> result = spiralOrder(matrix);
  sort(result.begin(), result.end());

  for (int num : result) {
    cout << num << " ";
  }

  return 0;
}
