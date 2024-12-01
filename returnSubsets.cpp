#include <iostream>
#include <vector>

using namespace std;

void getAllSubsets(vector<int> &nums, vector<int> &ans, int i,
                   vector<vector<int>> &allSubsets) {
  if (i == nums.size()) {
    allSubsets.push_back({ans});
    return;
  }

  // Include
  ans.push_back(nums[i]);
  getAllSubsets(nums, ans, i + 1, allSubsets);

  ans.pop_back(); // Backtrack
  // Exclude
  getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> allSubsets;
  vector<int> ans;

  getAllSubsets(nums, ans, 0, allSubsets);

  return allSubsets;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans;

  ans = subsets(nums);

  for (const auto &nums : ans) {
    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
