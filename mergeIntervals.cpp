#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  vector<vector<int>> result;
  
  sort(intervals.begin(), intervals.end());

  result.push_back(intervals[0]);

  for (int i = 1; i < intervals.size(); i++) {
    vector<int> &last = result.back();

    if (intervals[i][0] <= last[1]) {
      last[1] = max(last[1], intervals[i][1]);
    } else {
      result.push_back(intervals[i]);
    }
  }

  return result;
}

int main() {
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> result = merge(intervals);

  for (const auto &interval : result) {
    for (int num : interval) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
