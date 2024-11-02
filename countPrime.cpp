#include <iostream>
#include <vector>

using namespace std;

// SIEVE OF ERATOSTHENES ALGORITHM
int countPrimes(int n) {
  vector<bool> isPrime(n + 1, true);
  int count = 0;

  for (int i = 2; i < n; i++) {
    if (isPrime[i]) {
      count++;

      for (int j = i * 2; j < n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  return count;
}

int main() {
  int n = 50;
  cout << countPrimes(n);

  return 0;
}
