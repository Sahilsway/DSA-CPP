#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int> &nums) {
  int i = nums.size() - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) {
    i--;
  }
  if (i >= 0) {
    int j = nums.size() - 1;
    while (nums[j] <= nums[i]) {
      j--;
    }
    swap(nums[i], nums[j]);
  }
  reverse(nums.begin() + i + 1, nums.end());
}

void printVector(vector<int> &nums) {
  cout << "Next permutation:";
  for (int num : nums) {
    cout << " " << num;
  }
  cout << endl;
}

int main() {
  vector<int> nums = {3, 2, 1};
  nextPermutation(nums);
  printVector(nums);
  return 0;
}
