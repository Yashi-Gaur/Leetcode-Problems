class Solution {
public:
    int reverse(int x) {
        int n = 0;
        int ans = 0;

        while(x!=0) {
            n++;
            int num = x%10;
            x = x/10;
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            ans = ans*10+num;
        }
        return ans;
    }
};