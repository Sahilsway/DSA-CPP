#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
  int low = 0, high = nums.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    if (nums[low] <= nums[mid]) {
      if (nums[low] <= target && target < nums[mid]) {
        high = mid - 1;
      } else
        low = mid + 1;
    } else {
      if (nums[mid] < target && target <= nums[high]) {
        low = mid + 1;
      } else
        high = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {5, 1, 3};
  int target = 3;
  cout << search(nums, target);
  return 0;
}
