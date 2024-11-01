#include <iostream>

using namespace std;

int main() {
  string s = "raceca";
  cout << (s == string(s.rbegin(), s.rend()));
  return 0;
}
