class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> nums, vector<int> subset, int i) {
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }
        backtrack(nums, subset, i+1);
        subset.push_back(nums[i]);
        backtrack(nums, subset, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, {}, 0);
        return ans;
    }
};