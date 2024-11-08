#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
  int i = 0, n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> triplets;

  for (int i = 0; i < n - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int left = i + 1, right = n - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];

      if (sum == 0) {
        triplets.push_back({nums[i], nums[left], nums[right]});

        while (left < right && nums[left] == nums[left + 1])
          left++;
        while (left < right && nums[right] == nums[right - 1])
          right--;

        left++, right--;
      } else if (sum < 0) {
        left++;
      } else {
        right--;
      }
    }
  }
  return triplets;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> triplets = threeSum(nums);

  for (const auto &triplet : triplets) {
    for (int num : triplet) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
