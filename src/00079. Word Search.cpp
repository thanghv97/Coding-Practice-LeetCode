class Solution {
public:
    vector<int> xi, yi;
    
    bool recursion(const vector<vector<char>>& board, const string &word,
                   vector<vector<bool>>& check, int i, int j, int cs) {
        check[i][j] = true;
        
        for (int k = 0; k < 4; k++) {
            int ii = i + xi[k];
            int jj = j + yi[k];
            if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size() && 
                !check[ii][jj] && board[ii][jj] == word[cs+1]) {
                if (cs + 1 == word.length() - 1 || recursion(board, word, check, ii, jj, cs + 1)) {
                    return true;
                }
            }
        }

        check[i][j] = false;        
            
        return false;    
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> check(n, vector<bool>(m, false));
        xi = vector<int>{0, -1, 0, 1};
        yi = vector<int>{-1, 0, 1, 0};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    if (word.length() == 1 || recursion(board, word, check, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};