// 1 4 5 6 7
// 1 4 5 7 6
// 1 4 6 5 7
// 1 4 6 7 5
// 1 4 7 5 6
// 1 4 7 6 5
// 1 5 4 6 7

// 2 7 1 3 5 4 4 1
// 2 7 1 4 1 3 4 5

// 2 7 1 4 5 4 3 1
// 2 7 1 1 3 4 4 5
// 
// 2 7 1 5 1 3 4 4
// 2 7 1 5 1 4 3 4
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int switchingPoint = -1;
        int pivot = -1;
        for(int i = n-1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                switchingPoint = i-1;
                pivot = nums[i-1];
                break;
            }
        }
        if(switchingPoint == -1) sort(nums.begin(), nums.end());
        else {
            sort(nums.begin() + switchingPoint, nums.end());

            for(int j = switchingPoint; j < n; j++) {
                if(nums[j] > pivot) {
                    int temp = nums[switchingPoint];
                    nums[switchingPoint] = nums[j];
                    nums[j] = temp;
                    sort(nums.begin() + switchingPoint + 1, nums.end());
                    break;
                }
            }
        }
        
    }
};