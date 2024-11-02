#include <cmath>
#include <iostream>

using namespace std;

void countOfDigits(int num) {
  int count = 0;
  cout << "Number of digits: " << (int)(log10(num) + 1) << endl;
  while (num != 0) {
    count++;
    num /= 10;
  }
  cout << "Number of digits: " << count << endl;
}

void sumOfDigits(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  cout << "Sum of digits: " << sum << endl;
}

void printDigits(int num) {
  cout << "Digits: ";
  while (num != 0) {
    cout << num % 10 << " ";
    num /= 10;
  }
  cout << endl;
}

int main() {
  int num = 3568;
  countOfDigits(num);
  sumOfDigits(num);
  printDigits(num);

  return 0;
}
