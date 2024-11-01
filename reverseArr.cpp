#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Using temp array - O(n)TIME, O(n)SPACE
void reverseArrTemp(vector<int> &arr) {
  int n = arr.size();
  vector<int> temp(n);

  for (int i = 0; i < arr.size(); i++)
    temp[i] = arr[n - i - 1];

  for (int i = 0; i < arr.size(); i++)
    arr[i] = temp[i];
}

// Using 2 pointers - O(n)TIME, O(1)SPACE
void reverseArrTwoPointers(vector<int> &arr) {
  int left = 0, right = arr.size() - 1;

  while (left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
  }
}

// Iterating half the array - O(n)TIME, O(1)SPACE
void reverseArrHalfIteration(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n / 2; i++) {
    swap(arr[i], arr[n - i - 1]);
  }
}

// Using recursive - O(n)TIME, O(n)SPACE
void reverseArrRec(vector<int> &arr, int l, int r) {
  if (l >= r)
    return;
  swap(arr[l], arr[r]);

  reverseArrRec(arr, l + 1, r - 1);
}
void reverseArrRecEntry(vector<int> &arr) {
  int n = arr.size();
  reverseArrRec(arr, 0, n - 1);
}

// Using inbuild reverse method - O(n)TIME, O(1)SPACE
void reverseArrInbuiltMethod(vector<int> &arr) {
  reverse(arr.begin(), arr.end());
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  // reverseArrTemp(arr);
  // reverseArrTwoPointers(arr);
  // reverseArrHalfIteration(arr);
  // reverseArrRecEntry(arr);
  reverseArrInbuiltMethod(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << ", ";
  }
  return 0;
}
