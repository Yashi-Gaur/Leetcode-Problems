class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = costs[0];
        if(sum > coins) return 0;
        int n = costs.size();
        for(int i = 1; i < n; i++) {
            sum += costs[i];
            if(sum > coins) return i;
        }
        return n;
    }
};