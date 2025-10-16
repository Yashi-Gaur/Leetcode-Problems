class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mod(value, 0);

        for(int i  = 0; i < nums.size(); i++) {
            int m = (nums[i] % value + value) % value;
            mod[m]++;        
        }
        int smallest = mod[0];
        int smallest_index = 0;
        for(int i = 1; i < value; i++){
            if(mod[i] < smallest) {
                smallest = mod[i];
                smallest_index = i;
            }
        }
        return smallest*value + smallest_index;
    }
};