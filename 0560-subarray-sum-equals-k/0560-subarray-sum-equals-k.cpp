class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        long long sum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            // if(sum == k) res++;
            if(mp.find(sum - k) != mp.end()) {
                res += mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};

/*

1 1 1
1 2 3 

*/