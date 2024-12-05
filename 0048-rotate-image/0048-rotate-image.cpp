class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++) {
            for(int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }

    }
};

/*

1 2 3
4 5 6
7 8 9

1 4 7
2 5 8
3 6 9


[[5,1,9,11]
[2,4,8,10]
[13,3,6,7]
[15,14,12,16]]

[[15,5,13,1]
[3,2,4,14]
[8,9,6,7]
[10,11,12,16]]






*/