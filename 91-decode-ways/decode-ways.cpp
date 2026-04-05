// 12063425
// 1 20 6 3 4 2 5
// 1 20 6 3 4 25

// 1212345
// 1 2 1 2 3 4 5 
// 12 1 2 3 4 5
// 12 12 3 4 5
// 12 1 23 4 5
// 1 2 12 3 4 5
// 1 2 1 23 4 5
// 1 21 2 3 4 5
// 1 21 23 4 5

// 1 -> 1
// 12 -> 2
// 121 -> 2 + 1 = 3
// 1212 -> 3 + 2 = 5
// 12123 -> 5 + 3 = 8
// 121234 -> 8
// 1212345 -> 5

// 12102427
// 1-> 1
// 12-> 2
// 121 -> 3
// 1210 -> check i-1 == 1 or 2 then == i-2 = 2
// 12102 -> if i-1 == 0 then == i-1 = 2
// 121024 -> i-1 + i-2 = 2 + 2
// 1210242 -> if i-1 > 2 || x > 6 == i-1 = 4
// 12102427 -> 4

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ways(n, 0);
        if(s[0] - '0' == 0) return 0;
        if(n == 1) return 1;
        ways[0] = 1;
        int previous = s[0] - '0';
        int digit = s[1] - '0';
        if(digit == 0 && previous > 2) return 0;
        if(digit == 0 || previous > 2 || (previous == 2 && digit > 6)) ways[1] = 1;
        else ways[1] = 2;

        for(int i = 2; i < n; i++) {
            previous = digit;
            digit = s[i] - '0';

            if(digit == 0) {
                if(previous == 0 || previous > 2) return 0;
                else ways[i] = ways[i-2];
            }
            else if(previous == 0 || previous > 2 || (previous == 2 && digit > 6)) {
                ways[i] = ways[i-1];
            }
            else {
                ways[i] = ways[i-1] + ways[i-2];
            }
        }
        return ways[n-1];
    }
};