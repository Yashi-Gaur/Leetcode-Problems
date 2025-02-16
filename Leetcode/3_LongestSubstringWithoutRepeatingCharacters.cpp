class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < s.size(); i++) {
            len++;
            if(m.find(s[i]) != m.end()) {
                len = min(len, i-m[s[i]]);
            }
            ans = max(ans, len);
            m[s[i]] = i;
        }
        return ans;
    }
};