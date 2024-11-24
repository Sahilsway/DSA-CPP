#include <iostream>
#include <vector>

using namespace std;

int searchNum(vector<int> nums, int target, int str, int end) {
  if (str > end) {
    return -1;
  }

  int mid = str + (end - str) / 2;

  if (nums[mid] == target) {
    return mid;
  } else if (nums[mid] < target) {
    return searchNum(nums, target, mid + 1, end);
  } else {
    return searchNum(nums, target, str, mid - 1);
  }

  return -1;
}

int main() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  cout << searchNum(nums, 9, 0, nums.size() - 1) << endl;

  return 0;
}
