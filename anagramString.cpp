#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
  if (s.length() != t.length())
    return false;

  vector<int> freq(26, 0);

  for (int i = 0; i < s.length(); i++) {
    freq[s[i] - 'a']++;
    freq[t[i] - 'a']--;
  }

  for (int count : freq) {
    if (count != 0)
      return false;
  }

  return true;
}

int main() {
  string s = "anagram", t = "nagaram";
  cout << (isAnagram(s, t) ? "true" : "false");

  return 0;
}