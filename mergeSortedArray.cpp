#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, int m, vector<int> &B, int n) {
  int i = m - 1;
  int j = n - 1;
  int idx = m + n - 1;

  while (i >= 0 && j >= 0) {
    if (A[i] > B[j]) {
      // A[idx--] = A[i--];
      A[idx] = A[i];
      i--;
      idx--;
    } else {
      // A[idx--] = B[j--];
      A[idx] = B[j];
      j--;
      idx--;
    }
  }
  while (j >= 0) {
    A[idx--] = B[j--];
  }
}

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;

  merge(nums1, m, nums2, n);

  for (int num : nums1) {
    cout << num << " ";
  }

  return 0;
}
