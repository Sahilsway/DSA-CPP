#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int findMinDiff(vector<int> &arr, int m) {
  int n = arr.size();

  sort(arr.begin(), arr.end());

  int minDiff = INT_MAX;

  for (int i = 0; i + m - 1 < n; i++) {
    int diff = arr[i + m - 1] - arr[i];

    if (diff < minDiff)
      minDiff = diff;
  }
  return minDiff;
}

void printVector(vector<int> &arr) {
  cout << "Sorted array:";
  for (int num : arr) {
    cout << " " << num;
  }
  cout << endl;
}

int main() {
  vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
  int m = 3;

  cout << findMinDiff(arr, m);
  return 0;
}
