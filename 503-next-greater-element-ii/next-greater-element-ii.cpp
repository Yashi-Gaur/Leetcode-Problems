class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>> s;
        vector<int> ans(n);
        s.push({nums[0], 0});
        for(int i = 1; i < nums.size(); i++) {
            while(!s.empty() && nums[i] > s.top().first) {
                ans[s.top().second] = nums[i];
                s.pop();
            }
            s.push({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++) {
            while(!s.empty() && nums[i] > s.top().first) {
                ans[s.top().second] = nums[i];
                s.pop();
            }
            if(s.top().second == i) {
                while(!s.empty()) {
                    ans[s.top().second] = -1;
                    s.pop();
                }
                break;
            }
        }
        return ans;
    }
};