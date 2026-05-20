class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> dp(n+1, 0);
        vector<int> dp_p(n+1, 0);
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s1[j] == s2[i]) dp[j] = 1 + dp_p[j+1];
                else dp[j] = max(dp[j+1], dp_p[j]);
            }
            dp_p = dp;
        }
        return dp[0];
    }
};