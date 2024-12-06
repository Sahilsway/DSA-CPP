#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
  unordered_map<char, char> matching = {{')', '('}, {'}', '{'}, {']', '['}};
  stack<char> stk;

  for (char ch : s) {
    if (matching.count(ch)) {
      if (stk.empty() || stk.top() != matching[ch]) {
        return false;
      }
      stk.pop();
    } else {
      stk.push(ch);
    }
  }

  return stk.empty();
}

int main() {
  string s = "{[()]}";
  cout << isValid(s) << endl;

  return 0;
}
