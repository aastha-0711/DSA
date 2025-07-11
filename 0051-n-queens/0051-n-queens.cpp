class Solution {
    vector<vector<string>> results;
    vector<string> board;
    private:
    bool isSafe(int row, int col, int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0; --i,--j){
            if(board[i][j]=='Q'){return false;}
        }
    
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
 void solve(int row, int n) {
        if (row == n) {
            results.push_back(board);
            return;
        }
 for (int col = 0; col < n; ++col) {
            if (isSafe(row, col, n)) {
                board[row][col] = 'Q';
                solve(row + 1, n);
                board[row][col] = '.'; // Backtrack
            }
        }
 }
 public:
    vector<vector<string>> solveNQueens(int n) {
        board=vector<string>(n,string(n,'.'));
        solve(0,n);
        return results;
    }
};