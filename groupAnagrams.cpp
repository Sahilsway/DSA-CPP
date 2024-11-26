#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> anagramGroups;

  for (string str : strs) {
    string sortedStr = str;
    sort(sortedStr.begin(), sortedStr.end());
    anagramGroups[sortedStr].push_back(str);
  }

  vector<vector<string>> result;
  for (auto pair : anagramGroups) {
    result.push_back(pair.second);
  }

  return result;
}

int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> ans = groupAnagrams(strs);

  for (auto group : ans) {
    for (string word : group) {
      cout << word << " ";
    }
    cout << endl;
  }

  return 0;
}
