class Solution {
    void solve(int i, int n, int sum, int tar, vector<int>& v, vector<int> arr, vector<vector<int>>& nums) {
        if(sum > tar || i == n) return;
        if(sum == tar) {
            nums.push_back(arr);
            return; 
        }

        // not pick
        solve(i+1, n, sum, tar, v, arr, nums);

        //pick 
        arr.push_back(v[i]);
        solve(i, n, sum + v[i], tar, v, arr, nums);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        solve(0, n, 0, tar, nums, {}, ans);

        return ans;
    }
};