#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void rotateArr(vector<int> &arr, int d) {
  // int n = arr.size();
  if (d > arr.size()) {
    d = d % arr.size();
  }
  // int i = 0, j = d - 1;
  // while (i < j) {
  //   swap(arr[i], arr[j]);
  //   i++, j--;
  // }
  // int dCopy = d, k = n - 1;
  // while (dCopy < k) {
  //   swap(arr[dCopy], arr[k]);
  //   dCopy++, k--;
  // }
  // i = 0, j = n - 1;
  // while (i < j) {
  //   swap(arr[i], arr[j]);
  //   i++, j--;
  // }

  reverse(arr.begin(), arr.begin() + d);
  reverse(arr.begin() + d, arr.end());
  reverse(arr.begin(), arr.end());
}

int main() {
  vector<int> arr = {1, 0};
  int d = 101;
  rotateArr(arr, d);

  for (int num : arr) {
    cout << num << " ";
  }

  return 0;
}
