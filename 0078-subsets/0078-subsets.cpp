class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m = 1 << n;

        vector<vector<int>> res;

        for(int i=0; i<m; i++) { // 0 1 2 3 4 5 6 7
            vector<int> temp;
            for(int j=0; j<n; j++) { // 0 1 2
                if((1 << j) & i) 
                temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};