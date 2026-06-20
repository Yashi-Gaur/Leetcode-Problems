class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp_1(amount+1, 0);
        dp_1[0] = 1;
        int n = coins.size();
        for(int i = 0; i <= amount; i++) {
            if(i >= coins[n-1]) {
                dp_1[i] = dp_1[i-coins[n-1]];
            }
        }
        vector<unsigned int> dp(amount+1, 0);

        for(int i = n-2; i >= 0; i--) {
            dp[0] = 1;
            for(int j = 1; j <= amount; j++) {
                if(j >= coins[i]) {
                    dp[j] = dp[j-coins[i]] + dp_1[j];
                }
                else {
                    dp[j] = dp_1[j];
                }
            }
            dp_1 = dp;
        }

        return dp_1[amount];
    }
};