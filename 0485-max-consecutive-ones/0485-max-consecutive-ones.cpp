class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0, len = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] ==  1) len++;
            else len = 0;
            res = max(res, len);
        }
        return res;
    }
};