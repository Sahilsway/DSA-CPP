#include <iostream>

using namespace std;

int findGCD(int n1, int n2) {
  while (n1 != 0 && n2 != 0) {
    if (n1 > n2) {
      n1 %= n2;
    } else {
      n2 %= n1;
    }
  }
  return n1 == 0 ? n2 : n1;
}

// Find Greatest Common Divisor using Recursion + Euclid's Algorithm
int gcdRec(int n1, int n2) {
  if (n2 == 0)
    return n1;

  return gcdRec(n2, n1 % n2);
}

int findLcm(int n1, int n2) {
  int gcd = gcdRec(n1, n2);

  return (n1 * n2) / gcd;
}

int main() {
  int n1 = 20, n2 = 28;
  cout << findGCD(n1, n2) << endl;
  cout << gcdRec(n1, n2) << endl;
  cout << findLcm(n1, n2) << endl;

  return 0;
}
