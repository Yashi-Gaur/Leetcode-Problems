class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % 2) return false;

        int target = sum / 2;

        unordered_set<int> s;
        s.insert(0);
        for(int i = 0; i < n; i++) {
            unordered_set<int> s_new;
            for(auto &val: s) {
                int new_val = val + nums[i];
                if(new_val == target) return true;
                s_new.insert(new_val);
                s_new.insert(val);
            }
            s = s_new;
        }
        return false;
    }
};