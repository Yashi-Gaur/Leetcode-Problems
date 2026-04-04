class Solution {
public:
    vector<int> ans;
    void backtrack(vector<int> nums, int x, int i) {
        if(i == nums.size()) {
            ans.push_back(x);
            return;
        }

        x = x ^ nums[i];
        backtrack(nums, x, i+1);

        x = x ^ nums[i];
        backtrack(nums, x, i+1);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        backtrack(nums, 0, 0);
        for(int i = 0; i < ans.size(); i++) {
            sum += ans[i];
        }
        return sum;
    }
};