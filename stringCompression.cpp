#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char> &chars) {
  int n = chars.size();
  int idx = 0;

  for (int i = 0; i < n;) {
    char ch = chars[i];
    int count = 0;
    while (i < n && chars[i] == ch) {
      count++;
      i++;
    }
    if (count == 1) {
      chars[idx++] = ch;
    } else {
      chars[idx++] = ch;
      string str = to_string(count);
      for (char digit : str) {
        chars[idx++] = digit;
      }
    }
    count = 0;
    ch = chars[i];
  }
  chars.resize(idx);
  return chars.size();
}

int main() {
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  cout << compress(chars) << endl;

  return 0;
}
