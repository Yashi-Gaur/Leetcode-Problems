class Solution {
public:
    int knapsack(vector<int>& stones, int n, int i, int target, vector<vector<int>> &memo) {
        if(i == n || target == 0) return 0;

        if(memo[target][i] != -1) return memo[target][i];

        int best = knapsack(stones, n, i+1, target, memo);
        if(stones[i] <= target) {
            best = max(best, stones[i] + knapsack(stones, n, i+1, target-stones[i], memo));
        }
        memo[target][i] = best;
        return best;
    }
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        int sum = 0;
        int n = stones.size();
        for(int i = 0; i < n; i++) {
            sum += stones[i];
        }
        int target = sum/2;

        vector<vector<int>> memo(target+1, vector<int>(n, -1));

        int closestToTarget = knapsack(stones, n, 0, target, memo);

        int ans = sum - 2*closestToTarget;

        return ans;
    }
};