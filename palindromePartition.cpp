#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isPalin(string s) {
  string sTemp = s;
  reverse(sTemp.begin(), sTemp.end());

  return s == sTemp;
}

void getAllParts(string s, vector<vector<string>> &ans,
                 vector<string> &partitions) {
  if (s.size() == 0) {
    ans.push_back(partitions);
    return;
  }

  for (int i = 0; i < s.size(); i++) {
    string part = s.substr(0, i + 1);

    if (isPalin(part)) {
      partitions.push_back(part);
      getAllParts(s.substr(i + 1), ans, partitions);
      partitions.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> ans;
  vector<string> partitions;

  getAllParts(s, ans, partitions);

  return ans;
}

int main() {
  string s = "aab";
  vector<vector<string>> ans = partition(s);

  for (const auto row : ans) {
    for (string pal : row) {
      cout << pal;
    }
    cout << endl;
  }

  return 0;
}
