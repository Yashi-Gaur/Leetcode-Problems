class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(nums[j] == 0)
        {
            j--;
            if(j < 0) break;
        } 
        while(i <= j)
        {
            if(nums[i] == 0)
            {
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                j--;
            }
            else i++;
        }
    }
};