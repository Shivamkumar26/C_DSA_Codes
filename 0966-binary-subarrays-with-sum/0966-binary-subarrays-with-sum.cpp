class Solution {
    int solve(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, i = 0, sum = 0, count = 0;

        while(i < n) {
            sum += nums[i];
            while(sum > t && l <= i) {
                sum -= nums[l++];
            }
            count += (i-l+1);
            i++;
        }
        return count;

    }
public:
    int numSubarraysWithSum(vector<int>& nums, int tar) {
        return solve(nums, tar) - solve(nums, tar-1);
    }
};