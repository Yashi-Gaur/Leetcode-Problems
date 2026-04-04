class Solution {
public:
    int ans;
    void backtrack(unordered_map<char, int> m, int n, int count) {
        ans++;
        if(count == n) {
            return;
        }
        for(int i = 0; i < m.size(); i++) {
            if(m[i] > 0) {
                m[i]--;
                backtrack(m, n, count+1);
                m[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> m;
        int n = tiles.size();
        for(int i = 0; i < n; i++) m[tiles[i]]++;
        backtrack(m, n, 0);
        return ans-1;
    }
};