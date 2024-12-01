#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void getallsubsets(vector<int> &nums, vector<int> &ans, int i,
                   vector<vector<int>> &allsubsets) {
  if (i == nums.size()) {
    allsubsets.push_back({ans});
    return;
  }

  // include
  ans.push_back(nums[i]);
  getallsubsets(nums, ans, i + 1, allsubsets);

  ans.pop_back(); // backtrack
  int idx = i + 1;
  while (idx < nums.size() && nums[idx] == nums[idx - 1])
    idx++;
  // exclude
  getallsubsets(nums, ans, idx, allsubsets);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> allsubsets;
  vector<int> ans;

  getallsubsets(nums, ans, 0, allsubsets);

  return allsubsets;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans;

  ans = subsetsWithDup(nums);

  for (const auto &nums : ans) {
    for (int num : nums) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
