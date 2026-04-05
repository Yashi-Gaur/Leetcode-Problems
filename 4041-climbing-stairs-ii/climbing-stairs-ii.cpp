class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int x_3 = costs[0] + 1;
        if(n == 1) return x_3;
        int x_2 = costs[1] + min(4, x_3 + 1);
        if(n == 2) return x_2;
        int x_1 = costs[2] + min(9, min(x_2 + 1, x_3 + 4));
        if(n == 3) return x_1;

        int min_cost = 0;
        for(int i = 4; i <= n; i++) {
            min_cost = costs[i-1] + min(x_1 + 1, min(x_2 + 4, x_3 + 9));

            x_3 = x_2;
            x_2 = x_1;
            x_1 = min_cost;
        }
        return min_cost;
    }
};