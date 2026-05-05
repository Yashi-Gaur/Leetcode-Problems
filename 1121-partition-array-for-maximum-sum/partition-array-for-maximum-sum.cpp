// 1,4,1,5,7,3,6,1,9,9,3
// 1,
// 4,4
// 4,4,4
// 5,5,5,5
// 1,7,7,7,7
// 4,4,7,7,7,7
// 4,4,7,7,7,7,5  4,4,4,7,7,7,7
// 5,5,5,5,7,7,7,7 4,4,4,7,7,7,7,6 4,4,7,7,7,7,6,6 1,7,7,7,7,6,6,6
// 1,7,7,7,7,9,9,9,9
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int curMax = 0, best = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k) {
                curMax = max(curMax, A[i - k]);
                best = max(best, dp[i - k] + curMax * k);
            }
            dp[i] = best; 
        }
        return dp[N];
    }
};