class Solution {
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, l = 0, i = 0, res = 0;

        while(i < n) {
            sum += nums[i];
            while(sum > k) {
                sum -= nums[l];
                l++;
            }
            res += i-l+1;
            i++;
        }
        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % 2 == 1) nums[i] = 1;
            else nums[i] = 0; 
        }
        return solve(nums, k) - solve(nums, k-1);
    }
};