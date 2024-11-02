#include <cmath>
#include <iostream>

using namespace std;

bool isArmstrong(int num) {
  int sum = 0, copyNum = num;
  while (num != 0) {
    sum += pow(num % 10, 3);
    num /= 10;
  }

  if (sum == copyNum) {
    return true;
  }

  return false;
}

int main() {
  int num = 153;
  cout << isArmstrong(num);

  return 0;
}
