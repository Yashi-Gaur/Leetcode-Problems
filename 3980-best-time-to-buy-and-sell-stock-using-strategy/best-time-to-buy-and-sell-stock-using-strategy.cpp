class Solution {
public:
    // 541246
    // 11-1-101 12
    // 001101 6 + 3 = 9
    // 100111 9+5-1+4 = 17
    // 110011 17+4-2+0 = 19
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long maxAns = 0;
        long long profit = 0;
        int n = prices.size();
        int mid = k/2;
        for(int i = 0; i < n; i++) {
            maxAns += prices[i]*strategy[i];
            if(i >= mid && i < k) profit += prices[i];
            else if(i >= k) profit += prices[i]*strategy[i];
        }
        maxAns = max(profit, maxAns);
        for(int i = k; i < n; i++, mid++) {
            profit += strategy[i-k]*prices[i-k] - prices[mid] + prices[i]*(1-strategy[i]);
            maxAns = max(profit, maxAns);
        }
        return maxAns;
    }
};