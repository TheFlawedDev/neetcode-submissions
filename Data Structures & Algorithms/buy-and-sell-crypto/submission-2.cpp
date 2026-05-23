class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // stores the lowest price seen thus far
    int buy = 101;
    // stores the highst profit
    int hProfit = 0;
    int rProfit = 0;

    for (int i = 0; i < prices.size(); i++) {
      if (i == prices.size() && prices[i] <= buy) return hProfit;

      // stores current price
      int cur = prices[i];
      int profit = cur - buy;

      // resets running profit (rProfit) given that a new low was found
      if (cur <= buy) {
        buy = cur;
        rProfit = 0;
        continue;
      } else if (profit > rProfit) {
        rProfit = profit;
      }

      if (rProfit > hProfit) {
        hProfit = rProfit;
      }
    }
    return hProfit;
  }
};
