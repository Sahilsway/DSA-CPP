#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {

  int n = nums.size();
  int count = 0;

  // for (int i = 0; i < n; i++) {
  //   int sum = 0;
  //   for (int j = i; j < n; j++) {
  //     sum += nums[j];
  //     if (sum == k)
  //       count++;
  //   }
  // }

  // unordered_map<int, int> prefixSumFreq;
  // prefixSumFreq[0] = 1;
  // int prefixSum = 0;
  // for (int num : nums) {
  //   prefixSum += num;
  //   if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
  //     count += prefixSumFreq[prefixSum - k];
  //   }
  //   prefixSumFreq[prefixSum]++;
  // }

  vector<int> prefixSum(n, 0);

  prefixSum[0] = nums[0];
  for (int i = 1; i < n; i++) {
    prefixSum[i] = prefixSum[i - 1] + nums[i];
  }

  unordered_map<int, int> m;
  for (int j = 0; j < n; j++) {
    if (prefixSum[j] == k)
      count++;

    int val = prefixSum[j] - k;
    if (m.find(val) != m.end()) {
      count += m[val];
    }
    m[prefixSum[j]]++;
  }

  return count;
}

int main() {
  vector<int> nums = {1, 1, 1};
  int k = 2;
  cout << subarraySum(nums, k) << endl;
  return 0;
}
