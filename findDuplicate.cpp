#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int> &nums) {
  // unordered_set<int> s;
  //
  // for (int num : nums) {
  //   if (s.find(num) != s.end()) {
  //     return num;
  //   }
  //   s.insert(num);
  // }
  // return -1;
  int slow = nums[0], fast = nums[0];

  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);

  slow = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}

int main() {
  vector<int> nums = {1, 3, 4, 2, 2};
  cout << findDuplicate(nums);

  return 0;
}
