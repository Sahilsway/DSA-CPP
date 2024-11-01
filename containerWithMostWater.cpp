#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
  int i = 0, j = height.size() - 1;
  int max_area = 0;

  while (i < j) {
    // Calculate the area using the shorter height between height[i] and height[j]
    int area = min(height[i], height[j]) * (j - i);
    max_area = max(max_area, area);

    // Move the pointer pointing to the shorter height inward
    if (height[i] < height[j]) {
      i++;
    } else {
      j--;
    }
  }
  return max_area;
}

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  cout << "Max area: " << maxArea(height) << endl;

  return 0;
}
