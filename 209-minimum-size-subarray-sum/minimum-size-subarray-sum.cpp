class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int ans = n+1;
        int sum = nums[0];
        while(j < n) {
            if(sum < target) {
                j++;
                if(j < n)sum += nums[j];
            }
            else {
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        if(ans > n) return 0;
        return ans;
    }
};