#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
  unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10},
                                    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  int ans = 0;

  for (int i = 0; i < s.length(); i++) {
    // If the current numeral is smaller than the next, subtract it
    if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
      ans -= roman[s[i]];
    } else {
      ans += roman[s[i]];
    }
  }

  return ans;
}

int main() {
  string s = "III";
  cout << romanToInt(s) << endl;
  return 0;
}
