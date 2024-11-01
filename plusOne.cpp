#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
  int n = digits.size();

  for (int i = n - 1; i >= 0; i--) {
    if (digits[i] < 9) {
      digits[i]++;
      return digits;
    }
    digits[i] = 0;
  }

  digits.insert(digits.begin(), 1);
  return digits;
}

int main(int argc, char *argv[]) {
  vector<int> digits = {4, 3, 2, 1};
  plusOne(digits);

  for (int num : digits) {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}
