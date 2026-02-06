/*

2,1,7,5,3,4,6; k=2
1,2,3,4,5,6,7
1,2 => 5
2,3,4 => 4
3,4,5,6 => 3
4,5,6,7 => 3

1,2,3,4,5,6,7
2 3 4 4 3 2 1
*/


class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        int toKeep = 0;
        int temp = 0;
        sort(nums.begin(), nums.end());
        if(k == 1) {
            temp = 1;
            for(int i = 1; i < n; i++) {
                if(nums[i] == nums[i-1]) temp++;
                else {
                    toKeep = max(toKeep, temp);
                    temp = 1;
                }
            }
            return n - max(toKeep, temp);
        }
        int maxN = nums[n-1];
        int i = 0; 
        int j = 0;
        while(j < n) {
            if((long long)nums[j] <= (long long)nums[i]*k) {
                temp++;
                j++;
            }
            else {
                toKeep = max(temp, toKeep);
                while((long long)nums[j] > (long long)nums[i]*k) {
                    i++;
                    if(temp > 0)temp--;
                }
            }
        }
        toKeep = max(temp, toKeep);
        return n-toKeep;
    }
};