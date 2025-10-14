class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leastSoFar = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < leastSoFar) leastSoFar = prices[i];
            if(prices[i] - leastSoFar > maxProfit) maxProfit = prices[i] - leastSoFar;
        }
        return maxProfit;
    }
};