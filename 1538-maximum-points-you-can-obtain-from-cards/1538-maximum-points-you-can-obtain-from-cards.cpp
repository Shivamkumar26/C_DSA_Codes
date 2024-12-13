class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 0), suf(n, 0);

        for(int i=0; i<k; i++) {
            pre[i] = nums[i] + (i-1 >= 0 ? pre[i-1] : 0);
            cout << pre[i] <<" ";
        }
        cout << endl;

        for(int i=n-1; i>=0; i--) {
            suf[i] = nums[i] + (i+1 < n ? suf[i+1] : 0);
            cout << suf[i] << " ";
        }
        cout << endl;

        int mx = max({mx, pre[k-1], suf[n-k]});

        for(int i=0; i<k-1; i++) {
            mx = max(mx, pre[i] + suf[n+i-k+1]);
            cout << "mx "  << mx << " ";
        }
        return mx;
    }
};
/*
1 2 3 4 5 6 1 


1 3 6 4 12 7 1

*/