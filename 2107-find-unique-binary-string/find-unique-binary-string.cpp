/*
00 01 10 11 
000 001 010 011 100 101 110 111 1000
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s(nums.begin(), nums.end());
        int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; i++) ans += "0";
        int flip_i = n-1;
        while(s.find(ans) != s.end()) {
            ans[flip_i] = '1';
            int flag = 0;
            for(int i = flip_i+1; i < n; i++){
                ans[i] = '0';
                flag++;
            }
            if(flag > 0) {
                flip_i = n-1;
            }
            else {
                while(ans[flip_i] == '1' && flip_i > 0) flip_i--;
            }
        }
        return ans;
    }
};