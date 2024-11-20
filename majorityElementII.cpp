#include <iostream>
#include <vector>

using namespace std;

vector<int> findMajority(vector<int> &arr) {
  vector<int> ans;

  if (arr.size() == 1) {
    ans.push_back(arr[0]);
    return ans;
  }

  int n = arr.size();
  int candidate1 = 0, count1 = 0;
  int candidate2 = 0, count2 = 0;

  for (int num : arr) {
    if (num == candidate1) {
      count1++;
    } else if (num == candidate2) {
      count2++;
    } else if (count1 == 0) {
      candidate1 = num;
      count1++;
    } else if (count2 == 0) {
      candidate2 = num;
      count2++;
    } else {
      count1--, count2--;
    }
  }

  count1 = count2 = 0;
  for (int num : arr) {
    if (num == candidate1)
      count1++;
    else if (num == candidate2)
      count2++;
  }

  if (count1 > n / 3 && count2 > n / 3) {
    if (candidate1 < candidate2) {
      ans.push_back(candidate1);
      ans.push_back(candidate2);
    } else {
      ans.push_back(candidate2);
      ans.push_back(candidate1);
    }
  } else {
    if (count1 > n / 3) {
      ans.push_back(candidate1);
    }
    if (count2 > n / 3) {
      ans.push_back(candidate2);
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {1, 3};
  vector<int> ans = findMajority(arr);

  for (int num : ans) {
    cout << num << " ";
  }

  return 0;
}
