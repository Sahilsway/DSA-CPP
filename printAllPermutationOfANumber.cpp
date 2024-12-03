#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> &arr, vector<vector<int>> &ans, int index) {
  if (index == arr.size()) {
    ans.push_back({arr});
    return;
  }

  for (int i = index; i < arr.size(); i++) {
    swap(arr[index], arr[i]);
    backtrack(arr, ans, index + 1);
    swap(arr[index], arr[i]);
  }
}

vector<vector<int>> findPermutations(vector<int> &arr) {
  vector<vector<int>> ans;
  backtrack(arr, ans, 0);
  return ans;
}

int main() {
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> ans = findPermutations(arr);

  for (const auto &nums : ans) {
    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
