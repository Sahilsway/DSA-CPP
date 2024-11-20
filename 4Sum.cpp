#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
  int n = nums.size();
  vector<vector<int>> quadruplets;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    for (int j = i + 1; j < n;) {

      int left = j + 1, right = n - 1;

      while (left < right) {
        long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

        if (sum == target) {
          quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
          left++;
          right--;

          while (left < right && nums[left] == nums[left - 1])
            left++;
          // while (left < right && nums[right] == nums[right - 1]) right--;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
      j++;
      while (j < n && nums[j] == nums[j - 1])
        j++;
    }
  }
  return quadruplets;
}

int main() {
  int target = 8;
  vector<int> nums = {2, 2, 2, 2, 2};
  vector<vector<int>> triplets = fourSum(nums, target);

  for (const auto &triplet : triplets) {
    for (int num : triplet) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
