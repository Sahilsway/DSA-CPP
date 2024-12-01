#include <iostream>
#include <vector>

using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
  if (i == arr.size()) {
    for (int num : ans) {
      cout << num << " ";
    }
    cout << endl;
    return;
  }

  // Include
  ans.push_back(arr[i]);
  printSubsets(arr, ans, i + 1);

  ans.pop_back(); // Backtrack
  // Exclude
  printSubsets(arr, ans, i + 1);
}

int main() {
  vector<int> arr = {1, 2, 3};
  vector<int> ans;

  printSubsets(arr, ans, 0);

  return 0;
}
