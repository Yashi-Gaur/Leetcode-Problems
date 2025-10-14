class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> letters;
        for(int i = 0; i < s.length(); i++) {
            letters[s[i]]++;
            letters[t[i]]--;
        }
        for (auto i : letters) {
            if(i.second) return false; 
        }
        return true;
    }
};