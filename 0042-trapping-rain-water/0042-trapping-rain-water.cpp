class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0], rmax = height[n-1], l = 0, r = n-1;
        int ans = 0;

        while(l < r) {
            if(lmax <= rmax) {
                l++;
                lmax = max(lmax, height[l]);
                ans += lmax - height[l];
            }
            else {
                r--;
                rmax = max(rmax, height[r]);
                ans += rmax - height[r];
            }
        }
        return ans;
    }
};
/*

0 1 0 2 1 0 1 3 2 1 2 1
      l               r

= 1

*/