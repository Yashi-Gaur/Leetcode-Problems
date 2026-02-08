class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            int sum = -(nums[i]);
            int l = i+1;
            int u = nums.size()-1;
            while(l<u)
            {
                if(nums[l] + nums[u] == sum)
                {
                    s.insert({nums[i], nums[l], nums[u]});
                    l++;
                    u--;
                }
                else if(nums[l] + nums[u] > sum) u--;
                else l++;
            }
        }
        for(auto triplets : s)
            ans.push_back(triplets);
        return ans;
    }
};