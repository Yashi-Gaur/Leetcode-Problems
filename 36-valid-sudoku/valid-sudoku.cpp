class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> row(9);
        vector<unordered_map<char, int>> col(9);
        vector<unordered_map<char, int>> box(9);

        for(int i = 0; i < 3; i++) {
            for(int j = i*3; j < 3*(i+1); j++) {
                for(int k = 0; k < 9; k++) {
                    // cout << k << "," << j << "," << i*3+k/3 << "," << board[k][j] << endl;
                    if(board[k][j] == '.') continue;
                    if(row[k][board[k][j]] > 0) return false;
                    row[k][board[k][j]]++;
                    if(col[j][board[k][j]] > 0) return false;
                    col[j][board[k][j]]++;
                    if(box[i*3+k/3][board[k][j]] > 0) return false;
                    box[i*3+k/3][board[k][j]]++;
                }
            }
        }

        return true;
    }
};