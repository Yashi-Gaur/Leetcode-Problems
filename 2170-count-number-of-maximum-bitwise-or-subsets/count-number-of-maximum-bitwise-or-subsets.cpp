class Solution {
public:
    int getCount(int i, int curr_or, vector<int>& nums, int max_or) {
        if(i == nums.size()) {
            if(curr_or == max_or) return 1;
            else return 0;
        }
        return getCount(i+1, curr_or, nums, max_or) + 
               getCount(i+1, curr_or | nums[i], nums, max_or);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            max_or |= nums[i];
        }
        
        return getCount(0, 0, nums, max_or);
    }
};