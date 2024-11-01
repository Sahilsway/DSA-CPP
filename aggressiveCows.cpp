#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &stalls, int n, int c, int minAllowedDistance) {
  int cows = 1, lastStallPos = stalls[0];

  for (int i = 1; i < n; i++) {
    if (stalls[i] - lastStallPos >= minAllowedDistance) {
      cows++;
      lastStallPos = stalls[i];
    }

    if (cows == c) {
      return true;
    }
  }
  return false;
}

long long getDistance(vector<int> &stalls, int n, int c) {
  sort(stalls.begin(), stalls.end());

  int str = 1, end = stalls[n - 1] - stalls[0], ans = -1;

  while (str <= end) {
    int mid = str + (end - str) / 2;

    if (isPossible(stalls, n, c, mid)) {
      ans = mid;
      str = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

int main() {
  vector<int> stalls = {1, 2, 8, 4, 9};
  int n = stalls.size();
  int c = 3;
  cout << getDistance(stalls, n, c);

  return 0;
}
