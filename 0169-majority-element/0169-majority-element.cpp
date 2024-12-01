class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 1, nu = nums[0];
        for(int i=1; i<n; i++) {
            if(nums[i] == nu) {
                c++;
            }
            else {
                c--;
            }
            if(c == 0) nu = nums[i], c=1;
        }
        return nu;
    }
};