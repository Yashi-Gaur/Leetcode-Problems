class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int left = 0;
        int ans = 0;
        for(int i = 0; i < nums.size()-1; i++) {

            left += nums[i];
            if((2*left-sum)%2 == 0) ans++;
        }
        return ans;
    }
};