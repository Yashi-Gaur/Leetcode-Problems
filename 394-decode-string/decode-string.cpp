class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<string> st;
        stack<int> nums;
        int mul = 0;
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9') mul = mul*10+(s[i]-'0');
            else if(s[i] == '[')
            {
                st.push(ans);
                nums.push(mul);
                mul = 0;
                ans = "";
            }
            else if(s[i] == ']')
            {
                string temp = ans;
                for(int j = 1; j < nums.top(); j++) ans+=temp;
                ans = st.top() + ans;
                nums.pop();
                st.pop();
            }
            else ans += s[i];
        }
        return ans;
    }
};