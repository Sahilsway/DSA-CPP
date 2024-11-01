// #include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int> &nums, int k) {
  // Initialize an empty list
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Add first k elements to the list
  for (int i = 0; i < k; i++)
    minHeap.push(nums[i]);

  // Loop through the remaining elements in the 'nums' array
  for (int i = k; i < nums.size(); i++) {
    // Compare the current element with the minimum
    // element (root) of the min-heap
    if (nums[i] > minHeap.top()) {
      // Remove the smallest element
      minHeap.pop();
      // Add the current element
      minHeap.push(nums[i]);
    }
  }

  // The root of the heap has the Kth largest elemenvectort
  return minHeap.top();
}

// int findKthLargest(vector<int> &nums, int k) {
//   int count = 0;
//   int largest = INT_MIN;
//
//   while (count != k) {
//     largest = INT_MIN;
//     int maxIdx = -1;
//
//     for (int i = 0; i < nums.size(); i++) {
//       if (nums[i] > largest) {
//         largest = nums[i];
//         maxIdx = i;
//       }
//     }
//     count++;
//     nums[maxIdx] = INT_MIN;
//   }
//   return largest;
// }

int main(int argc, char *argv[]) {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << findKthLargest(nums, k);
  return 0;
}
