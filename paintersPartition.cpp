#include <iostream>
#include <vector>

using namespace std;

bool isPartition(vector<int> &boards, int n, int m, int maxAllowedPartition) {
  int painters = 1, time = 0;

  for (int i = 0; i < n; i++) {
    if (time + boards[i] <= maxAllowedPartition) {
      time += boards[i];
    } else {
      painters++;
      time = boards[i];
    }
  }
  return painters <= m;
}

long long findPartition(vector<int> &boards, int n, int m) {

  int str = boards[0];
  int end = 0;

  for (int i = 0; i < n; i++) {
    str = max(str, boards[i]);
    end += boards[i];
  }

  int ans = -1;
  while (str <= end) {
    int mid = str + (end - str) / 2;

    if (isPartition(boards, n, m, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      str = mid + 1;
    }
  }

  return ans;
}

int main() {
  vector<int> boards = {40, 30, 10, 20};
  int n = boards.size();
  int m = 2;
  cout << findPartition(boards, n, m);

  return 0;
}
