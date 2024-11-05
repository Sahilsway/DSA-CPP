#include <iostream>

using namespace std;

int findDiagonalSum(int matrix[][4], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    // for (int j = 0; j < n; j++) {
    //   if (i == j) {
    //     sum += matrix[i][j];
    //   } else if (j == n - i - 1) {
    //     sum += matrix[i][j];
    //   }
    // }
    sum += matrix[i][i];

    if (i != n - i - 1) {
      sum += matrix[i][n - i - 1];
    }
  }
  return sum;
}

int main() {
  int n = 4;
  int matrix[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  cout << "Total diagonal sum: " << findDiagonalSum(matrix, n);

  return 0;
}
