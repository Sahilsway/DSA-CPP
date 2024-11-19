#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  unordered_set<int> charSet;
  int start = 0, maxSubStr = 0;

  for (int i = 0; i < s.length(); i++) {

    while (charSet.find(s[i]) != charSet.end()) {
      charSet.erase(s[start]);
      start++;
    }

    charSet.insert(s[i]);
    maxSubStr = max(maxSubStr, i - start + 1);
  }
  return maxSubStr;
}

int main() {
  string s = "pwwkew";

  cout << lengthOfLongestSubstring(s);

  return 0;
}
