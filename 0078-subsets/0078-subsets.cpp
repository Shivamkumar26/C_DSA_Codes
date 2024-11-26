class Solution {
    void solve(int i, int n, vector<int>& nums, vector<int> arr, vector<vector<int>>& ans) {
        if(i == n) {
            ans.push_back(arr); 
            return; 
        }

        solve(i+1, n, nums, arr, ans);
        arr.push_back(nums[i]);
        solve(i+1, n, nums, arr, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(0, n, nums, {}, ans);
        return ans; 
    }
};