#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums) {
  int ans = 0;
  for (int num : nums) {
    ans ^= num;
  }
  return ans;
}

int main() {
  vector<int> nums = {4, 4, 2, 1, 2};
  cout << singleNumber(nums);

  return 0;
}
