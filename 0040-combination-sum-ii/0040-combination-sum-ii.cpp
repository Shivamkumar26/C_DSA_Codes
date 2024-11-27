class Solution {
    void solve(int i, int n, int sum, int tar, vector<int>& nums, vector<int> arr, vector<vector<int>>& res) {
        if(sum == tar) {
            res.push_back(arr);
            return;
        }
        if(i == n || sum > tar) return;

        for(int j=i; j<n; j++) {
            if(j != i && nums[j] == nums[j-1]) continue;

            arr.push_back(nums[j]);
            solve(j+1, n, sum + nums[j], tar, nums, arr, res);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        solve(0, n, 0, tar, nums, {}, res);
        return res;
    }
};