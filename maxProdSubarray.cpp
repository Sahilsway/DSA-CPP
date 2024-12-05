#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int> &arr) {
  int n = arr.size();

  int currMax = arr[0], currMin = arr[0], maxProd = arr[0];

  for (int i = 1; i < n; i++) {

    int temp = max({arr[i], arr[i] * currMax, arr[i] * currMin});

    currMin = min({arr[i], arr[i] * currMax, arr[i] * currMin});

    currMax = temp;

    maxProd = max(maxProd, currMax);
  }
  return maxProd;
}

int main() {
  vector<int> arr = {-2, 6, -3, -10, 0, 2};
  cout << maxProduct(arr) << endl;
  return 0;
}
