class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> m;
        unordered_map<int, int> rev_m;

        for(int i = 0; i < s.length(); i++) {
            if(m.find(s[i] - 'a') == m.end()){
                if(rev_m.find(t[i] - 'a') == rev_m.end()) {
                    m[s[i] - 'a'] = t[i] - 'a';
                    rev_m[t[i] - 'a'] = s[i] - 'a';
                }
                else return false;
            } 
            else if(m[s[i] - 'a'] != t[i] - 'a') return false;
        }

        return true;
    }
};