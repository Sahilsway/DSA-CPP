#include <climits>
#include <iostream>

using namespace std;

int reverse(int num) {
  int revNum = 0;
  while (num != 0) {
    int dig = num % 10;
    if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
      return 0;
    }
    revNum = revNum * 10 + dig;
    num /= 10;
  }
  return revNum;
}

bool isPalindrome(int num) {
  if (num < 0) {
    return 0;
  }

  int revNum = reverse(num);

  return num == revNum;
}

int main() {
  int num = 353;
  cout << isPalindrome(num);

  return 0;
}
