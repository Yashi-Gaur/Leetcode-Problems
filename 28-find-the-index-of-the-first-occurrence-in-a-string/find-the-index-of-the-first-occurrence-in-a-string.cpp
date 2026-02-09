class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> index;
        int j = 0;
        for(int i = 0; i < haystack.size(); i++) {
            if(haystack[i] == needle[0]) {
                index.push_back(i);
            }
        }
        for(int i = 0; i < index.size(); i++) {
            int k = 0;
            for(int j = index[i]; i < haystack.size(); j++) {
                if(haystack[j] == needle[k]) {
                    k++;
                    if(k == needle.size()) return index[i];
                }
                else break;
            }
        }
        return -1;
    }
};