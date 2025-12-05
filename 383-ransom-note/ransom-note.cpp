class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        for(int i = 0; i < magazine.length(); i++){
            letters[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            if(letters[ransomNote[i]] == 0) return 0;
            letters[ransomNote[i]]--;
        }
        return true;
    }
};