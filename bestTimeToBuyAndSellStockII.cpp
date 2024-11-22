#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
  if (prices.empty())
    return 0;

  int maxProfit = 0;

  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] > prices[i - 1]) {
      maxProfit += prices[i] - prices[i - 1];
    }
  }
  return maxProfit;
}

int main() {
  vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
  cout << "Max possible profit: " << maxProfit(prices);
  return 0;
}
