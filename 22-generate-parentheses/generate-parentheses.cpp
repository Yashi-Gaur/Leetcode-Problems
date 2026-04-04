class Solution {
public:
    vector<string> ans;
    void getCombinations(int n, int open, string c) {
        if(n > 0) {
            getCombinations(n-1, open+1, c+"(");
        }
        if(open > 0) {
            getCombinations(n, open-1, c+")");
        }
        if(n == 0 && open == 0) ans.push_back(c);
    }
    vector<string> generateParenthesis(int n) {
        ans = {};
        getCombinations(n, 0, "");
        return ans;
    }
};

