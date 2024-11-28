class Solution {
    bool solve(int i, int j, int n, int m, int idx, string& word, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        if(idx == word.size()) {
            return true;
        }
        if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j]==1 || word[idx] != grid[i][j]) return false;

        vis[i][j] = 1;

        bool res = solve(i+1, j, n, m, idx+1, word, grid, vis) || 
        solve(i, j+1, n, m, idx+1, word, grid, vis) ||
        solve(i-1, j, n, m, idx+1, word, grid, vis) || 
        solve(i, j-1, n, m, idx+1, word, grid, vis);
        
        vis[i][j] = 0;
        return res;
    }
public:
    bool exist(vector<vector<char>>& grid, string word) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
               if(solve(i, j, n, m, 0, word, grid, vis)) 
                    return true;
            }
        }
        return false;
    }
};