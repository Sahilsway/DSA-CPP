#include <iostream>

using namespace std;

bool isAlphaNum(char ch) {
  return ch >= '0' && ch <= '9' || tolower(ch) >= 'a' && tolower(ch) <= 'z';
}

bool isPalindrome(string s) {
  // return s == string(s.rbegin(), s.rend());

  int str = 0, end = s.length() - 1;
  while (str < end) {

    if (!isAlphaNum(s[str])) {
      str++;
      continue;
    }
    if (!isAlphaNum(s[end])) {
      end--;
      continue;
    }

    if (tolower(s[str]) != tolower(s[end])) {
      return false;
    }
    str++;
    end--;
  }
  return true;
}

int main() {
  string s = "A man, a plan, a canal: Panama";
  cout << isPalindrome(s);
  return 0;
}
