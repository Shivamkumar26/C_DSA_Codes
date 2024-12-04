class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> mp;

        for(int i=0; i<n; i++) mp.insert(nums[i]);

        int res = 0;
        for(auto it : mp) {
            if(mp.find(it-1) == mp.end()) {
                int len = 1;
                int ele = it + 1;
                while(mp.find(ele) != mp.end()) {
                    len++;
                    ele++;
                }
                res = max(len, res);
            }
        }
        return res;
    }
};