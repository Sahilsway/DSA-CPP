#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
  if (prices.empty())
    return 0;

  int minPrice = prices[0];
  int maxProfit = 0;

  for (int i = 1; i < prices.size(); i++) {
    minPrice = min(minPrice, prices[i]);

    maxProfit = max(prices[i] - minPrice, maxProfit);
  }
  return maxProfit;
}

int main() {
  vector<int> prices = {7, 1, 3, 4, 6, 1};
  cout << "Max possible profit: " << maxProfit(prices);
  return 0;
}
