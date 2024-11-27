class Solution {
    void solve(int i, int n, vector<int>& nums, vector<int> arr, vector<vector<int>>& res) {
        res.push_back(arr);

        for(int j = i; j < n; j++) {
            if(i != j && nums[j] == nums[j-1]) continue;

            arr.push_back(nums[j]);
            solve(j+1, n, nums, arr, res);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        solve(0, n, nums, {}, res);
        return res;
    }
};