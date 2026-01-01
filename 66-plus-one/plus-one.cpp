class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int sum = digits[digits.size()-1] + 1;
        int carry = sum > 9? 1:0;
        ans.push_back(sum%10);
        for(int i = digits.size()-2; i >= 0; i--) {
            sum = digits[i] + carry;
            ans.push_back(sum%10);
            carry = sum > 9? 1:0;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};