class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, res = 0;
        int i = 0, kk = k; 

        while(i < n) {
            if(nums[i] != 1) {
                kk--;
                if(kk == -1) {
                    while(l <= i && nums[l] != 0) {
                        l++;
                    }
                    l++;
                    kk++;
                }
            }
            res = max(res, i-l+1);
            cout << "res " << res << " l " << l << " r " << i << endl;
            i++;
        }
        return res;
    }
};