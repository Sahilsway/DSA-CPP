#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char> &s) { reverse(s.begin(), s.end()); }

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  reverseString(s);
  for (char ch : s) {
    cout << ch;
  }

  return 0;
}
