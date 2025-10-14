class Solution {
public:
    bool isAlphaNumeric(char c) {
        if((tolower(c) >= 'a' && tolower(c) <= 'z') || (c >= '0' && c <= '9') ) return true;
        return false;
    }
    bool isPalindrome(string s) {
        string new_s = "";
        for(int i = 0; i  < s.length(); i++) {
            if(isAlphaNumeric(tolower(s[i]))) new_s += tolower(s[i]);
        }
        for(int i = 0, j = new_s.length()-1; i  < new_s.length()/2; i++, j--) {
            if(new_s[i] != new_s[j]) return false;
        }
        return true;
    }
};