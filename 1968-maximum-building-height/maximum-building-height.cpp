class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.size() == 0) return n-1;
        vector<vector<int>> arr;
        arr.push_back({1,0});
        for(auto &x: restrictions) {
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        if (arr.back()[0] != n) {
            arr.push_back({n, n - 1});
        }

        int m = arr.size();
        for(int i = 1; i < m; i++) {
            int d = arr[i][0] - arr[i-1][0];
            arr[i][1] = min(arr[i-1][1] + d, arr[i][1]);
        }
        for(int i = m-2; i >= 0; i--) {
            int d = arr[i+1][0] - arr[i][0];
            arr[i][1] = min(arr[i+1][1] + d, arr[i][1]);
        }
        int maxHeight = 0;
        for(int i = 0; i < m-1; i++) {
            int d = arr[i+1][0] - arr[i][0];
            int h = (arr[i][1] + arr[i+1][1] + d)/2;
            maxHeight = max(maxHeight, h);
        }
        return maxHeight;
    }
};       