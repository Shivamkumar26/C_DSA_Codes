class Solution {
    bool canPlaceQueen(int c, int r, vector<string>& board, int n) {
        if(r < 0 || c < 0 || r >= n || c >= n) return false;

        int tempc = c;
        int tempr = r;

        // check up - diagonal 
        tempc--, tempr--;
        while(tempc >= 0 && tempr >= 0) {
            if(board[tempr][tempc] == 'Q')
                return false;
            tempr--, tempc--;
        }

        // check down -diagonal
        tempr = r+1, tempc = c-1;
        while(tempc >= 0 && tempr < n) {
            if(board[tempr][tempc] == 'Q')
                return false;
            tempr++, tempc--;
        }

        // check horizontal 
        tempc = c-1;
        while(tempc >= 0) {
            if(board[r][tempc] == 'Q') {
                return false;
            }
            tempc--;
        }
        return true;
    }
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& res) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int i=0; i<n; i++) {
            if(canPlaceQueen(col, i, board, n)) {
                board[i][col] = 'Q';
                solve(col+1, n, board, res);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;

        string st = "";
        for(int i=0; i<n; i++) {
            st += '.';
        }
        for(int i=0; i<n; i++) {
            board.push_back(st);
            cout << st << " ";
        }

        solve(0, n, board, res);
        return res;
    }
};
