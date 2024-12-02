class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        // sort(nums.begin(), nums.end());
        int n = nums.size(), res = INT_MAX;

        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l <= r) {
            int mid =  l + (r-l)/2;
            int count = 0;
            bool flag = true;
            for(int i=0; i<n; i++) {
                count += (nums[i]/mid + (nums[i] % mid == 0 ? 0 : 1));
                if(count > h) {
                    flag = false; 
                    break;
                }
            }
            if(flag) {
                res = min(res, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return res;
    }
};
/*
12 + 23

l=1
h=11

*/