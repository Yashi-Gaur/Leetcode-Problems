class Solution {
public:
    vector<string> ans;
    void getStrings(vector<string> &ans, vector<string> &l, int i, string curr)
    {
        if(i == l.size())
        {
            ans.push_back(curr);
            return;
        }
        for(auto c: l[i]) getStrings(ans, l, i+1, curr+c);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> l;
        int n = digits.size();
        if(!n) return l;
        for(int i = 0; i < n; i++)
        {
            if(digits[i] == '2') l.push_back("abc");
            if(digits[i] == '3') l.push_back("def");
            if(digits[i] == '4') l.push_back("ghi");
            if(digits[i] == '5') l.push_back("jkl");
            if(digits[i] == '6') l.push_back("mno");
            if(digits[i] == '7') l.push_back("pqrs");
            if(digits[i] == '8') l.push_back("tuv");
            if(digits[i] == '9') l.push_back("wxyz");
        }
        getStrings(ans, l, 0,"");
        return ans;
    }
};