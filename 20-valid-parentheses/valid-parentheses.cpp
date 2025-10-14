class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push(s[i]);
            }
            else {
                if(open.empty()) return false;
                if((s[i] == ')' && open.top() == '(') || (s[i] == ']' && open.top() == '[') || (s[i] == '}' && open.top() == '{')) {
                    open.pop();
                }
                else return false;
            }
        } 
        if(open.empty()) return true;
        return false;
    }
};