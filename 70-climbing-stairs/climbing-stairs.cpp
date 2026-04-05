class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int previous_1 = 1;
        int previous = 2;

        int ans = 0;

        for(int i = 3; i <= n; i++) {
            ans = previous + previous_1;

            previous_1 = previous;
            previous = ans;
        }
        return ans;
    }
};