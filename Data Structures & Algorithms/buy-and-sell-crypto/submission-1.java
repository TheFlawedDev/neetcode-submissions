class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;

        for(int i = 0; i < prices.length; i++){
            System.out.print(maxProfit + ", ");
            for(int j = i + 1; j < prices.length; j++){
                if(maxProfit < (prices[j] - prices[i])){
                    maxProfit = (prices[j] - prices[i]);
                }
            }
            if(i == prices.length && maxProfit != 0){
                return maxProfit;
            }
        }
        return maxProfit;
    }
}
