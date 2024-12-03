#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtrack(string &s, vector<vector<string>> &res, int idx) {
  if (idx == s.length()) {
    res.push_back({s});
    return;
  }

  for (int i = idx; i < s.length(); i++) {
    swap(s[idx], s[i]);
    backtrack(s, res, idx + 1);
    swap(s[idx], s[i]);
  }
}

vector<vector<string>> findAllPermutation(string &s) {
  vector<vector<string>> res;
  backtrack(s, res, 0);

  return res;
}

int main() {
  string s = "abc";
  vector<vector<string>> res = findAllPermutation(s);

  for (const auto &strs : res) {
    for (string str : strs) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}
