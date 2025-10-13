class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        sort(words[0].begin(), words[0].end());
        string curr = words[0];
        for(int i = 1; i < words.size(); i++) {
            string next = words[i];
            sort(words[i].begin(), words[i].end());
            if(curr != words[i]) {
                ans.push_back(next);
                curr = words[i];
            }
        }
        return ans;
    }
};