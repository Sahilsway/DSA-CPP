#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int mid) {
  int count = 0, n = arr.size();
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && arr[j] - arr[i] <= mid) {
      ++j;
    }
    count += (j - i - 1);
  }
  return count;
}

int findSmallestDifference(vector<int> &arr, int k) {
  sort(arr.begin(), arr.end());
  int low = 0, high = arr.back() - arr.front(), result = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (countPairs(arr, mid) >= k) {
      result = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return result;
}

int main() {
  vector<int> arr = {1, 2, 3, 4};
  int k = 3;
  cout << findSmallestDifference(arr, k) << endl;
  return 0;
}
