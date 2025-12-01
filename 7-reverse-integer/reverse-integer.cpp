class Solution {
public:
    int reverse(int x) {
        int temp = x;
        int temp_n = 0;
        int dig_1 = x%10;
        cout << dig_1;
        while(temp != 0) {
            temp_n++;
            if(temp_n > 9) {
                if(abs(dig_1) > 2) return 0;
            }
            temp /= 10;
        }
        int n = 0;
        int ans = 0;
        int sign = 0;
        if(x >= 0) sign = 1;
        else sign = -1;
        x *= sign;

        while(x!=0) {
            n++;
            int num = x%10;
            x = x/10;
            if(n > 9) {
                if(ans > 214748364) return 0;
            }
            ans = ans*10+num;
        }
        return ans*sign;
    }
};