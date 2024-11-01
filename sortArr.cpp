#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Print vector TODO: remove
void printVector(vector<int> &arr) {
  cout << "Sorted array:";
  for (int num : arr) {
    cout << " " << num;
  }
  cout << endl;
}

/*_*\ BUBBLE SORT \*_*/
void bubbleSort(vector<int> &arr, int n) {
  bool swaped = false;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swaped = true;
      }
    }
    if (!swaped) {
      break;
    }
  }
}

/*_*\ SELECTION SORT \*_*/
void selectionSort(vector<int> &arr, int n) {
  //   Poor version
  //   for (int i = 0; i < n - 1; i++) {
  //     for (int j = i + 1; j < n; j++) {
  //       if (arr[j] < arr[i]) {
  //         printVector(arr);
  //         swap(arr[i], arr[j]);
  //       }
  //     }
  //   }
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;

    for (int j = i + 1; j < n; ++j) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      swap(arr[i], arr[min_idx]);
    }
  }
}

/*_*\ INSERTION SORT \*_*/
void insertionSort(vector<int> &arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

/*_*\ MERGE SORT \*_*/
void merge(vector<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  cout << "merge: " << left << " " << mid << " " << right << endl;
  cout << "n1: " << n1 << ", "
       << "n2: " << n2 << endl;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  cout << "R :";
  printVector(L);
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];
  cout << "R :";
  printVector(R);
  int i = 0, j = 0;
  int k = left;
  while (i < n1 && j < n2) {
    cout << "while" << endl;
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(vector<int> &arr, int left, int right) {
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;
  cout << "bfr-break: " << left << " " << mid << " " << right << endl;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  cout << "break: " << left << " " << mid << " " << right << endl;
  merge(arr, left, mid, right);
}

/*_*\ QUICK SORT \*_*/
/* LOMUTO PARTITION */
// int partition(vector<int> &arr, int low, int high) {
//   int pivot = arr[high];
//   int i = (low - 1);
//
//   for (int j = low; j <= high - 1; j++) {
//     cout << "pivot: " << pivot << endl; // TODO: remove
//     if (arr[j] <= pivot) {
//       i++;
//       cout << "i: " << i << ", j: " << j << endl; // TODO: remove
//       swap(arr[i], arr[j]);
//     }
//   }
//   swap(arr[i + 1], arr[high]);
//   printVector(arr); // TODO: remove
//   return (i + 1);
// }
// void quickSort(vector<int> &arr, int low, int high) {
//   if (low < high) {
//     int pi = partition(arr, low, high);
//     cout << "pi: " << pi << endl; // TODO: remove
//
//     quickSort(arr, low, pi - 1);
//     quickSort(arr, pi + 1, high);
//   }
// }
/* HOARE'S PARTITION */
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while (true) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j)
      return j;
    swap(arr[i], arr[j]);
  }
}
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
  }
}

void heapSort(vector<int> &arr, int n) {}
void countingSort(vector<int> &arr, int n) {}

/**\ SORT 0's, 1's and 2's WITH COUNT \**/
void zotCountSort(vector<int> &arr, int n) {
  int zeros = 0, ones = 0, twos = 0;

  for (int i = 0; i < n; i++) {
    arr[i] == 0 ? zeros++ : arr[i] == 1 ? ones++ : twos++;
  }
  cout << zeros << ones << twos << endl;

  for (int i = 0; i < n; i++) {
    if (zeros > 0) {
      arr[i] = 0;
      zeros--;
    } else if (ones > 0) {
      arr[i] = 1;
      ones--;
    } else {
      arr[i] = 2;
      twos--;
    }
  }
}

/**\ Dutch National Flag algorithm (0, 1, 2) \**/
void dnfSort(vector<int> &arr, int n) {
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      mid++;
      low++;
    } else if (arr[mid] == 1) {
      mid++;
    } else {
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

int main() {

  vector<int> arr = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
  const int n = arr.size();
  // bubbleSort(arr, n);
  // selectionSort(arr, n);
  // insertionSort(arr, n);
  // mergeSort(arr, 0, n - 1);
  // quickSort(arr, 0, n - 1);
  heapSort(arr, n);
  countingSort(arr, n);

  dnfSort(arr, n);

  printVector(arr);
  return 0;
}
