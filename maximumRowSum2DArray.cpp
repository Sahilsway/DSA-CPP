#include <climits>
#include <iostream>

using namespace std;

// Maximum col sum
int maxColSum(int matrix[][3], int rows, int cols) {
  int maxColSum = INT_MIN;
  for (int i = 0; i < cols; i++) {
    int colSum = 0;
    for (int j = 0; j < rows; j++) {
      colSum += matrix[j][i];
    }
    maxColSum = max(maxColSum, colSum);
  }

  return maxColSum;
}

// Maximum row sum
int maxRowSum(int matrix[][3], int rows, int cols) {
  int maxRowSum = INT_MIN;
  for (int i = 0; i < rows; i++) {
    int rowSum = 0;
    for (int j = 0; j < cols; j++) {
      rowSum += matrix[i][j];
    }
    maxRowSum = max(maxRowSum, rowSum);
  }

  return maxRowSum;
}

int main() {
  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int rows = 3, cols = 3;
  // cout << maxRowSum(matrix, rows, cols);
  cout << maxColSum(matrix, rows, cols);

  return 0;
}
