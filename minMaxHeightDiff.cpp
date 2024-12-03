// C++ program to minimize the maximum difference between heights using Sorting

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
  int n = arr.size();
  sort(arr.begin(), arr.end());

  int res = arr[n - 1] - arr[0];

  for (int i = 1; i < arr.size(); i++) {

    if (arr[i] - k < 0)
      continue;

    int minH = min(arr[0] + k, arr[i] - k);
    cout << "For " << i << " minH = " << minH << endl;

    int maxH = max(arr[i - 1] + k, arr[n - 1] - k);
    cout << "For " << i << " maxH = " << maxH << endl;

    res = min(res, maxH - minH);
    cout << "For " << i << " res = " << res << endl;
  }
  return res;
}

int main() {

  int k = 6;
  vector<int> arr = {12, 6, 4, 15, 17, 10};

  int ans = getMinDiff(arr, k);
  cout << "Ans = " << ans << endl;

  return 0;
}
