class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) return true;
        int count = 1;
        for(int i = 1, j = k+1; j < nums.size(); i++, j++) {
            if(nums[i] > nums[i-1] && nums[j] > nums[j-1]) {
                count++;
                if(count == k) return true;
            }
            else {
                count = 1;
            }
        }
        return false;
    }
};