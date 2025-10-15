class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> inc;
        int count = 1;
        int max_count = 1;
        for(int i  = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) count++;
            else {
                inc.push_back(count);
                max_count =  max(max_count, count);
                count = 1;
            }
        }
        inc.push_back(count);
        max_count =  max(max_count, count);
        int ans = 1;
        for(int i = 1; i < inc.size(); i++) {
            ans = max(ans, min(inc[i], inc[i-1]));
        }
        return max(ans, max_count/2);
    }
};