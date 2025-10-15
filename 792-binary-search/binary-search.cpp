class Solution {
public:
    bool check(int n, int target) {
        if(n >= target) return true;
        return false;
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(!check(nums[right], target)) return -1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if(check(nums[mid], target)) right =  mid;
            else left = mid + 1;
        }
        if(nums[right] == target) return right;
        return -1;
    }
};