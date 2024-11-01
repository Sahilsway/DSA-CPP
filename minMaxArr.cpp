#include <iostream>
#include <iterator>
#include <limits.h>
using namespace std;

int setMini(int arr[], int n) {
  int mini = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] < mini) {
      mini = arr[i];
    }
  }
  return mini;
}

int setMax(int arr[], int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  int arr[5] = {3, 5, 4, 1, 9};
  // Find the size of array
  const int len = size(arr);
  // const int len = sizeof(arr) / sizeof(int);
  cout << "Minimun number: " << setMini(arr, len) << endl;
  cout << "Maximum number: " << setMax(arr, len);
  return 0;
}
