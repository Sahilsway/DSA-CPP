#include <stdio.h>
#include <stdlib.h>

int *repeatedNumber(const int *A, int n1, int *len1) {
  // Allocate memory for the result array
  int *result = (int *)malloc(2 * sizeof(int));
  *len1 = 2;

  long long sumN = 0, sumNSq = 0; // Sum of elements and sum of squares
  long long expectedSum = (long long)(n1 * (n1 + 1)) / 2;
  long long expectedSumSq = (long long)(n1 * (n1 + 1) * (2 * n1 + 1)) / 6;

  // Calculate the actual sum and sum of squares of array elements
  for (int i = 0; i < n1; i++) {
    sumN += (long long)A[i];
    sumNSq += (long long)A[i] * A[i];
  }

  // Calculate the differences
  long long diffSum = sumN - expectedSum;
  long long diffSumSq = sumNSq - expectedSumSq;

  // Solving the two equations:
  // A - B = diffSum
  // A^2 - B^2 = (A - B)(A + B) => diffSumSq = diffSum * (A + B)
  long long sumAplusB = diffSumSq / diffSum;

  // Now, we have two equations:
  // A - B = diffSum
  // A + B = sumAplusB
  // Solving for A and B:
  int A_num = (int)((diffSum + sumAplusB) / 2);
  int B_num = (int)(A_num - diffSum);

  // Fill the result array
  result[0] = A_num;
  result[1] = B_num;

  return result;
}

// Example test case
int main() {
  int A[] = {3, 1, 2, 5, 3};
  int n1 = 5;
  int len1;
  int *result = repeatedNumber(A, n1, &len1);

  printf("Repeated: %d, Missing: %d\n", result[0], result[1]);

  // Free allocated memory
  free(result);

  return 0;
}
