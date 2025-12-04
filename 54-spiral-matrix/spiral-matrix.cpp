class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int m = matrix.size();
        int j = 0; 
        int n = matrix[0].size();

        int r = 0;
        int c = 0;

        int forward = 1;
        int down = 0;
        int backward = 0;
        int up = 0;
        vector<int> ans;
        int count = 0;
        int total = m*n;
        while(count < total) {
            //cout << r << "," << c << "," << j << endl;
            count++;
            ans.push_back(matrix[r][c]);
            if(forward) {
                if(c < n-1) c++;
                else {
                    i++;
                    r++;
                    forward = 0;
                    down = 1;
                }
            }
            else if(down) {
                if(r < m-1) r++;
                else {
                    n--;
                    c--;
                    down = 0;
                    backward = 1;
                }
            }
            else if(backward) {
                if(c > j) c--;
                else {
                    m--;
                    r--;
                    backward = 0;
                    up = 1;
                }
            }
            else {
                if(r > i) r--;
                else {
                    j++;
                    c++;
                    up = 0;
                    forward = 1;
                }
            }
        }
        return ans;
    }
};