#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int> &candidates, int idx, int target,
                        vector<vector<int>> &ans, vector<int> &combin) {
  if (idx == candidates.size() || target < 0) {
    return;
  }

  if (target == 0) {
    if (s.find(combin) == s.end()) {
      ans.push_back({combin});
      s.insert(combin);
    }
    return;
  }

  combin.push_back(candidates[idx]);
  // Single
  getAllCombinations(candidates, idx + 1, target - candidates[idx], ans,
                     combin);
  // Multiple
  getAllCombinations(candidates, idx, target - candidates[idx], ans, combin);

  combin.pop_back();
  // Exclude
  getAllCombinations(candidates, idx + 1, target, ans, combin);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> ans;

  vector<int> combin;
  getAllCombinations(candidates, 0, target, ans, combin);

  return ans;
}

int main() {
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> ans = combinationSum(candidates, target);

  for (const auto nums : ans) {
    for (int num : nums) {
      cout << num;
    }
    cout << endl;
  }

  return 0;
}
