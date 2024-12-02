class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        if(n>=1) res.push_back({1});
        if(n>=2) res.push_back({1,1});

        for(int i=2; i<n; i++) {
            int col = i+1;
            vector<int> temp;
            for(int j=0; j<col; j++) {
                if(j==0 || j==col-1) temp.push_back(1);
                else temp.push_back(res[i-1][j-1] + res[i-1][j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};