class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int finalPos = n-1;

        for(int i = n-2; i >= 0; i--) {
            if(i + nums[i] >= finalPos) finalPos = i;
        }
        return finalPos == 0;
    }
};