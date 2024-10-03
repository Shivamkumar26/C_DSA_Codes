bool isValidSudoku(char** board, int n, int* m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < *m; j++) {
            
            char num = board[i][j];
            if(num == '.') continue;

            for(int r = 0; r < 9; r++) { // col check
                if(r == j) continue;
                if(num == board[i][r]) return false;
            }
            for(int c = 0; c < 9; c++) { // row check
                if(c == i) continue;
                if(num == board[c][j]) return false;
            }
            // box check
            // 0-1-2 = 0
            // 3-4-5 = 3
            // 6 7 8 = 6
            int rs = (i/3) * 3;
            int cs = (j/3) * 3;
            for(int r = rs; r < rs + 3; r++) {
                for(int c = cs; c < cs + 3; c++) {
                    if(i == r && j == c) continue;
                    if(num == board[r][c]) return false;
                }
            }
        }
    }
    return true;
}