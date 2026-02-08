class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> s;
        s.push(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            long long curr = (long long)nums[i];
            while(!s.empty() && s.top() == curr) {
                s.pop();
                curr += curr;
            }
            s.push(curr);
        }
        vector<long long> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};