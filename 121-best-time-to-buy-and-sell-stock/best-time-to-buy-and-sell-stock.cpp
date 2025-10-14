class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastSoFar = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            leastSoFar = min(prices[i], leastSoFar);
            maxProfit = max(maxProfit, prices[i] - leastSoFar);
        }
        return maxProfit;
    }
};