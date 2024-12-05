class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> visr(n, -1);
        vector<int> visc(m, -1);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    visr[i] = 0;
                    visc[j] = 0;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(visr[i] == 0) {
                for(int j=0; j<m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0; i<m; i++) {
            if(visc[i] == 0) {
                for(int j=0; j<n; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};