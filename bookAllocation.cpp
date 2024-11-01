#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> &pages, int n, int m, int maxAllowedPages) {
  int students = 1, currentPages = 0;

  for (int i = 0; i < n; i++) {
    if (pages[i] > maxAllowedPages) {
      return false;
    }

    if (currentPages + pages[i] <= maxAllowedPages) {
      currentPages += pages[i];
    } else {
      students++;
      currentPages = pages[i];
    }
  }
  return students > m ? false : true;
}

long long findPages(int n, vector<int> &pages, int m) {
  if (m > n) {
    return -1;
  }

  int str = 0;
  int end = 0;

  for (int i = 0; i < n; i++) {
    end += pages[i];
  }

  int ans = -1;
  while (str <= end) {
    int mid = str + (end - str) / 2;

    if (isValid(pages, n, m, mid)) {
      ans = mid;
      end = mid - 1;
    } else {
      str = mid + 1;
    }
  }

  return ans;
}

int main() {
  vector<int> pages = {12, 34, 67, 90};
  int n = pages.size();
  int m = 2;

  cout << findPages(n, pages, m);

  return 0;
}
