class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, int> even;
        unordered_map<char, int> odd;

        for(int i = 0; i < s1.size(); i+= 2) {
            even[s1[i]]++;
        }
        for(int i = 1; i < s1.size(); i+= 2) {
            odd[s1[i]]++;
        }

        for(int i = 0; i < s2.size(); i+= 2) {
            if(even.find(s2[i]) != even.end() && even[s2[i]] > 0) {
                even[s2[i]]--;
            }
            else return false;
        }
        for(int i = 1; i < s2.size(); i+= 2) {
            if(odd.find(s2[i]) != odd.end() && odd[s2[i]] > 0) {
                odd[s2[i]]--;
            }
            else return false;
        }

        return true;
    }
};