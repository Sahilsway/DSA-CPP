#include <iostream>
#include <vector>

using namespace std;

void pushZerosToEnd(vector<int> &arr) {
  int n = arr.size();
  int index = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      arr[index++] = arr[i];
    }
  }

  while (index < n) {
    arr[index++] = 0;
  }
}

int main() {
  vector<int> arr = {3, 5, 0, 0, 4};

  pushZerosToEnd(arr);

  for (int num : arr) {
    cout << num << " ";
  }

  return 0;
}
