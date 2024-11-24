#include <iostream>

using namespace std;

int printFibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return printFibonacci(n - 1) + printFibonacci(n - 2);
}

int main() {
  int n = 5;
  int result = printFibonacci(n);
  cout << result;

  return 0;
}
