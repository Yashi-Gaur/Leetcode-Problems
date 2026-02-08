class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int prod = 1;
        int zeroCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                zeroCount++;
                if(zeroCount >= 2) break;
                continue;
            } 
            prod *= nums[i];
        }
        if(zeroCount == 1) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) ans.push_back(prod);
                else ans.push_back(0);
            }
            return ans;
        }
        if(zeroCount >= 2) {
            vector<int> temp(nums.size(),0);
            return temp;
        }
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(prod/nums[i]);
        }
        return ans;
    }
};