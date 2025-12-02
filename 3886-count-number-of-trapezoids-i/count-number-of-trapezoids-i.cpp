class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> y;
        for(int i = 0; i < points.size(); i++){
            y[points[i][1]]++;
        }
        long long sum = 0;
        long long ans = 0;
        for(auto i: y) {
            int num = i.second;
            long long num_c_2 = (long long)num*(num-1)/2;

            ans += num_c_2*sum;
            ans %= mod;

            sum += num_c_2;
            sum %= mod;
        }
        return ans;
    }
};