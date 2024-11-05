#include <iostream>
#include <utility>

using namespace std;

// Return pair for the row and col of the key
pair<int, int> linearSearch(int matrix[][3], int rows, int cols, int key) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == key) {
        return make_pair(i, j);
      }
    }
  }
  return make_pair(-1, -1);
}

int main() {
  int matrix[4][3];
  int rows = 4, cols = 3, key = 8;
  cout << "Enter values for matrix: ";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }
  pair<int, int> p = linearSearch(matrix, rows, cols, key);
  cout << p.first << " " << p.second;

  return 0;
}
